# 🔧 RTOS Projects Using ESP32

A collection of **FreeRTOS** projects implemented on the **ESP32** microcontroller using the Arduino IDE. These projects explore core real-time operating system concepts such as task creation, task scheduling, and multitasking — essential building blocks for embedded systems development.

---

## 📁 Repository Structure

```
rtos-projects-using-esp32/
├── FreeRTOS_TASK_CREATION/   # Basic FreeRTOS task creation and execution
├── FreeRTOS_Scheduler/       # Task scheduling and priority management
└── FreeRTOS_TASK/            # Multi-task management on ESP32
```

---

## 📂 Projects Overview

### 1. 🟢 FreeRTOS_TASK_CREATION
**Basic FreeRTOS Task Creation**

An introductory example demonstrating how to create and run tasks using the FreeRTOS API on the ESP32. This project covers the fundamentals of spawning tasks with `xTaskCreate()` and understanding the lifecycle of an RTOS task.

Key concepts:
- Creating tasks with `xTaskCreate()`
- Task functions and infinite loops
- Serial output from concurrent tasks

---

### 2. 🔵 FreeRTOS_Scheduler
**Task Scheduling and Priority Management**

Explores how the FreeRTOS scheduler manages multiple tasks based on priority. Demonstrates preemptive scheduling and how the ESP32 handles context switching between tasks of different priorities.

Key concepts:
- Task priorities with `xTaskCreate()`
- Preemptive scheduling behavior
- `vTaskDelay()` for controlled task timing
- Observing scheduler-driven execution order

---

### 3. 🟠 FreeRTOS_TASK
**Multi-Task Management**

A hands-on project working with multiple concurrent tasks running on the ESP32. Explores how independent tasks can run simultaneously and how to pin tasks to specific CPU cores using `xTaskCreatePinnedToCore()`.

Key concepts:
- Running multiple tasks simultaneously
- Core affinity with `xTaskCreatePinnedToCore()`
- Task stack size configuration
- Task handles and lifecycle management

---

## 🛠️ Requirements

### Hardware
- ESP32 Development Board or MCU with multicore (e.g., ESP32 DevKit v1 or any ESP32-based board)
- USB cable for programming

### Software
- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8+ or v2.x)
- ESP32 Board Package — install via Arduino Board Manager:
  ```
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```
- FreeRTOS is **built into the ESP32 Arduino core** — no additional library installation needed

---

## 🚀 Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/R-MANI-KANDAN/rtos-projects-using-esp32.git
   cd rtos-projects-using-esp32
   ```

2. **Open a project** in Arduino IDE
   - Navigate to the desired project folder (e.g., `FreeRTOS_EXAMPLE_1`)
   - Open the `.ino` file

3. **Select your board**
   - Go to `Tools > Board > ESP32 Arduino`
   - Select your specific ESP32 board (e.g., `ESP32 Dev Module`)

4. **Select the correct port**
   - Go to `Tools > Port` and select the COM port for your ESP32

5. **Upload the code**
   - Click the **Upload** button (→)

6. **Open Serial Monitor**
   - Go to `Tools > Serial Monitor`
   - Set baud rate to `115200`
   - Observe task output in real time

---

## 📖 FreeRTOS Key Concepts

| Concept | Description |
|---|---|
| **Task** | An independent unit of execution, similar to a thread |
| **Scheduler** | Decides which task runs based on priority and state |
| **Priority** | Higher number = higher priority; the scheduler runs the highest-priority ready task |
| **vTaskDelay()** | Blocks a task for a given number of ticks, allowing other tasks to run |
| **xTaskCreate()** | Creates a new task and adds it to the ready queue |
| **xTaskCreatePinnedToCore()** | Creates a task pinned to a specific CPU core (Core 0 or Core 1) |
| **Stack Size** | Memory allocated to each task for its local variables and call stack |

---

## 🧠 Why FreeRTOS on ESP32?

The ESP32 has a dual-core Xtensa LX6 processor, making it an ideal platform for learning RTOS concepts:
- **Preemptive multitasking** — tasks run based on priority
- **Dual-core support** — tasks can be pinned to Core 0 or Core 1
- **Built-in FreeRTOS** — no extra setup required with the Arduino core
- **Real-time capability** — suitable for time-sensitive embedded applications

---
