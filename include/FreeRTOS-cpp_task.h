#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <functional>
#include <string>

namespace m2d
{
namespace FreeRTOS
{
	class Task
	{
	public:
		Task(std::string name, int priority, uint32_t stack_size, std::function<void()> task)
		{
			this->name = name;
			this->priority = priority;
			this->stack_size = stack_size;
			this->task = task;
		}

		~Task()
		{
			vTaskDelete(handle);
		}

		void run()
		{
			xTaskCreate(task_entry_point, this->name.c_str(), this->stack_size, this, this->priority, &handle);
		}

	protected:
		xTaskHandle handle = 0;
		std::string name;
		int priority;
		uint32_t stack_size;

		std::function<void()> task;

		static void task_entry_point(void *task_instance)
		{
			static_cast<Task *>(task_instance)->task();
		}
	};
}
}
