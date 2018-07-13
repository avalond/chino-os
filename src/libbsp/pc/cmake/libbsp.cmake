SET(BOARD_C_FLAGS "-fno-pie")
SET(BOARD_CXX_FLAGS "-fno-pie")
SET(BOARD_LDFLAGS "-Wl,-z,relro,-z,now -Wl,--no-dynamic-linker")

SET(ACPI_DIR ${DRIVER_DIR}/acpi)

SET(BSP_SRC ${ACPI_DIR}/Acpi.cpp
	${ACPI_DIR}/pci/Pci.cpp
	${ACPI_DIR}/bridge/Isa.cpp
	${ACPI_DIR}/storage/Ahci.cpp)