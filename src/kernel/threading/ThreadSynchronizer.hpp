//
// Chino Threading
//
#pragma once
#include "../object/Object.hpp"
#include <vector>
#include <atomic>
#include "../utils.hpp"
#include "ProcessManager.hpp"

namespace Chino
{
	namespace Threading
	{
		class Waitable : public Object, public FreeObjectAccess
		{
		public:
			void WaitOne();

		protected:
			void NotifyOne();
			void NotifyAll();
		private:
			std::vector<thread_it> waitingThreads_;
		};

		class Semaphore : public Waitable
		{
		public:
			Semaphore(size_t initialCount);

			void Take(size_t count);
			void Give(size_t count);
		private:
			std::atomic<size_t> count_;
		};

		class ThreadSynchronizer
		{
		public:
			ThreadSynchronizer();

		private:

		};
	}
}

extern StaticHolder<Chino::Threading::ThreadSynchronizer> g_ThreadSync;
