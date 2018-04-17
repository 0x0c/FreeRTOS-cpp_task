# FreeRTOS-cpp_task

Run FreeRTOS task using a lambda.

## Requirements

- esp-idf v2.1.1

## Usage

Like this

```
static m2d::FreeRTOS::Task task("Task name", 10, 1024 * 3, [&] {
	while (1) {
		this->emitter->update();
		vTaskDelay(DeviceConfiguration::LEDTaskDelay / portTICK_PERIOD_MS);
	}
});
task.run();


```

**DO NOT release a variable when task is running.**

## License

MIT