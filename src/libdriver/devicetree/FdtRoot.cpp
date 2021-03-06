//
// Kernel Device
//
#include "Fdt.hpp"
#include <libbsp/bsp.hpp>
#include <kernel/kdebug.hpp>
#include <kernel/device/DeviceManager.hpp>
#include <libfdt/libfdt.h>

extern const char _binary_devicetree_dtb_start[];
extern const char _binary_devicetree_dtb_end[];

using namespace Chino;
using namespace Chino::Device;

class FdtRootDriver : public Driver
{
public:
	virtual void Install() override
	{
		g_Logger->PutFormat("fdt: %z\n", _binary_devicetree_dtb_end - _binary_devicetree_dtb_start);
		std::vector<ObjectPtr<FDTDevice>> fdtDevices;
		int depth = 0;
		auto first_node = fdt_next_node(_binary_devicetree_dtb_start, -1, &depth);
		if (first_node >= 0)
			ForeachNode(fdtDevices, _binary_devicetree_dtb_start, first_node, depth);

		for (auto& device : fdtDevices)
			g_DeviceMgr->InstallDevice(device);
	}
private:
	void ForeachNode(std::vector<ObjectPtr<FDTDevice>>& fdtDevices, const void* fdt, int node, int depth)
	{
		fdtDevices.emplace_back(MakeObject<FDTDevice>(fdt, node, depth));
		int subnode;
		fdt_for_each_subnode(subnode, fdt, node)
		{
			ForeachNode(fdtDevices, fdt, subnode, fdt_node_depth(fdt, subnode));
		}
	}
};

Chino::ObjectPtr<Driver> Chino::Device::BSPInstallRootDriver(const BootParameters& bootParams)
{
	return MakeObject<FdtRootDriver>();
}
