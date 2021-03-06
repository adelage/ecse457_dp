/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'processor0_0_cpu0' in SOPC Builder design 'nios_fprint'
 * SOPC Builder design path: ../../nios_fprint.sopcinfo
 *
 * Generated: Sun Dec 07 18:20:17 EST 2014
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08000820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000001
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00464020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_ILLEGAL_MEMORY_ACCESS_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 1024
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_MPU_MIN_DATA_REGION_SIZE 1024
#define ALT_CPU_MPU_MIN_DATA_REGION_SIZE_LOG2 10
#define ALT_CPU_MPU_MIN_INST_REGION_SIZE 4096
#define ALT_CPU_MPU_MIN_INST_REGION_SIZE_LOG2 12
#define ALT_CPU_MPU_NUM_DATA_REGIONS 16
#define ALT_CPU_MPU_NUM_INST_REGIONS 8
#define ALT_CPU_MPU_PRESENT
#define ALT_CPU_NAME "processor0_0_cpu0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x00464000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08000820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000001
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00464020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_ILLEGAL_MEMORY_ACCESS_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 1024
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_MPU_MIN_DATA_REGION_SIZE 1024
#define NIOS2_MPU_MIN_DATA_REGION_SIZE_LOG2 10
#define NIOS2_MPU_MIN_INST_REGION_SIZE 4096
#define NIOS2_MPU_MIN_INST_REGION_SIZE_LOG2 12
#define NIOS2_MPU_NUM_DATA_REGIONS 16
#define NIOS2_MPU_NUM_INST_REGIONS 8
#define NIOS2_MPU_PRESENT
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x00464000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_MUTEX
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __CFPU
#define __CPU_IRQ
#define __FINGERPRINT
#define __UTLB


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Arria V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/processor0_0_jtag_uart"
#define ALT_STDERR_BASE 0x8001040
#define ALT_STDERR_DEV processor0_0_jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/processor0_0_jtag_uart"
#define ALT_STDIN_BASE 0x8001040
#define ALT_STDIN_DEV processor0_0_jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/processor0_0_jtag_uart"
#define ALT_STDOUT_BASE 0x8001040
#define ALT_STDOUT_DEV processor0_0_jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_fprint"


/*
 * cfpu_0 configuration
 *
 */

#define ALT_MODULE_CLASS_cfpu_0 cfpu
#define CFPU_0_BASE 0x1000000
#define CFPU_0_IRQ -1
#define CFPU_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CFPU_0_NAME "/dev/cfpu_0"
#define CFPU_0_SPAN 4096
#define CFPU_0_TYPE "cfpu"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK PROCESSOR0_0_TIMER
#define ALT_TIMESTAMP_CLK PROCESSOR0_0_TIMESTAMP


/*
 * memory_0_onchip_memoryMain configuration
 *
 */

#define ALT_MODULE_CLASS_memory_0_onchip_memoryMain altera_avalon_onchip_memory2
#define MEMORY_0_ONCHIP_MEMORYMAIN_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define MEMORY_0_ONCHIP_MEMORYMAIN_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define MEMORY_0_ONCHIP_MEMORYMAIN_BASE 0x400000
#define MEMORY_0_ONCHIP_MEMORYMAIN_CONTENTS_INFO ""
#define MEMORY_0_ONCHIP_MEMORYMAIN_DUAL_PORT 0
#define MEMORY_0_ONCHIP_MEMORYMAIN_GUI_RAM_BLOCK_TYPE "AUTO"
#define MEMORY_0_ONCHIP_MEMORYMAIN_INIT_CONTENTS_FILE "nios_fprint_memory_0_onchip_memoryMain"
#define MEMORY_0_ONCHIP_MEMORYMAIN_INIT_MEM_CONTENT 1
#define MEMORY_0_ONCHIP_MEMORYMAIN_INSTANCE_ID "NONE"
#define MEMORY_0_ONCHIP_MEMORYMAIN_IRQ -1
#define MEMORY_0_ONCHIP_MEMORYMAIN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEMORY_0_ONCHIP_MEMORYMAIN_NAME "/dev/memory_0_onchip_memoryMain"
#define MEMORY_0_ONCHIP_MEMORYMAIN_NON_DEFAULT_INIT_FILE_ENABLED 0
#define MEMORY_0_ONCHIP_MEMORYMAIN_RAM_BLOCK_TYPE "AUTO"
#define MEMORY_0_ONCHIP_MEMORYMAIN_READ_DURING_WRITE_MODE "DONT_CARE"
#define MEMORY_0_ONCHIP_MEMORYMAIN_SINGLE_CLOCK_OP 0
#define MEMORY_0_ONCHIP_MEMORYMAIN_SIZE_MULTIPLE 1
#define MEMORY_0_ONCHIP_MEMORYMAIN_SIZE_VALUE 1024000
#define MEMORY_0_ONCHIP_MEMORYMAIN_SPAN 1024000
#define MEMORY_0_ONCHIP_MEMORYMAIN_TYPE "altera_avalon_onchip_memory2"
#define MEMORY_0_ONCHIP_MEMORYMAIN_WRITABLE 1


/*
 * mutex_0 configuration
 *
 */

#define ALT_MODULE_CLASS_mutex_0 altera_avalon_mutex
#define MUTEX_0_BASE 0x2300000
#define MUTEX_0_IRQ -1
#define MUTEX_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MUTEX_0_NAME "/dev/mutex_0"
#define MUTEX_0_OWNER_INIT 0
#define MUTEX_0_OWNER_WIDTH 16
#define MUTEX_0_SPAN 8
#define MUTEX_0_TYPE "altera_avalon_mutex"
#define MUTEX_0_VALUE_INIT 0
#define MUTEX_0_VALUE_WIDTH 16


/*
 * processor0_0_Fingerprint_0 configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_Fingerprint_0 Fingerprint
#define PROCESSOR0_0_FINGERPRINT_0_BASE 0x8100000
#define PROCESSOR0_0_FINGERPRINT_0_IRQ -1
#define PROCESSOR0_0_FINGERPRINT_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSOR0_0_FINGERPRINT_0_NAME "/dev/processor0_0_Fingerprint_0"
#define PROCESSOR0_0_FINGERPRINT_0_SPAN 256
#define PROCESSOR0_0_FINGERPRINT_0_TYPE "Fingerprint"


/*
 * processor0_0_cpu_irq_0 configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_cpu_irq_0 cpu_irq
#define PROCESSOR0_0_CPU_IRQ_0_BASE 0x2200000
#define PROCESSOR0_0_CPU_IRQ_0_IRQ 1
#define PROCESSOR0_0_CPU_IRQ_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PROCESSOR0_0_CPU_IRQ_0_NAME "/dev/processor0_0_cpu_irq_0"
#define PROCESSOR0_0_CPU_IRQ_0_SPAN 1024
#define PROCESSOR0_0_CPU_IRQ_0_TYPE "cpu_irq"


/*
 * processor0_0_jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_jtag_uart altera_avalon_jtag_uart
#define PROCESSOR0_0_JTAG_UART_BASE 0x8001040
#define PROCESSOR0_0_JTAG_UART_IRQ 4
#define PROCESSOR0_0_JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PROCESSOR0_0_JTAG_UART_NAME "/dev/processor0_0_jtag_uart"
#define PROCESSOR0_0_JTAG_UART_READ_DEPTH 64
#define PROCESSOR0_0_JTAG_UART_READ_THRESHOLD 8
#define PROCESSOR0_0_JTAG_UART_SPAN 8
#define PROCESSOR0_0_JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define PROCESSOR0_0_JTAG_UART_WRITE_DEPTH 64
#define PROCESSOR0_0_JTAG_UART_WRITE_THRESHOLD 8


/*
 * processor0_0_scratchpad configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_scratchpad altera_avalon_onchip_memory2
#define PROCESSOR0_0_SCRATCHPAD_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define PROCESSOR0_0_SCRATCHPAD_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define PROCESSOR0_0_SCRATCHPAD_BASE 0x4200000
#define PROCESSOR0_0_SCRATCHPAD_CONTENTS_INFO ""
#define PROCESSOR0_0_SCRATCHPAD_DUAL_PORT 0
#define PROCESSOR0_0_SCRATCHPAD_GUI_RAM_BLOCK_TYPE "AUTO"
#define PROCESSOR0_0_SCRATCHPAD_INIT_CONTENTS_FILE "nios_fprint_processor0_0_scratchpad"
#define PROCESSOR0_0_SCRATCHPAD_INIT_MEM_CONTENT 1
#define PROCESSOR0_0_SCRATCHPAD_INSTANCE_ID "NONE"
#define PROCESSOR0_0_SCRATCHPAD_IRQ -1
#define PROCESSOR0_0_SCRATCHPAD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSOR0_0_SCRATCHPAD_NAME "/dev/processor0_0_scratchpad"
#define PROCESSOR0_0_SCRATCHPAD_NON_DEFAULT_INIT_FILE_ENABLED 0
#define PROCESSOR0_0_SCRATCHPAD_RAM_BLOCK_TYPE "AUTO"
#define PROCESSOR0_0_SCRATCHPAD_READ_DURING_WRITE_MODE "DONT_CARE"
#define PROCESSOR0_0_SCRATCHPAD_SINGLE_CLOCK_OP 0
#define PROCESSOR0_0_SCRATCHPAD_SIZE_MULTIPLE 1
#define PROCESSOR0_0_SCRATCHPAD_SIZE_VALUE 16384
#define PROCESSOR0_0_SCRATCHPAD_SPAN 16384
#define PROCESSOR0_0_SCRATCHPAD_TYPE "altera_avalon_onchip_memory2"
#define PROCESSOR0_0_SCRATCHPAD_WRITABLE 1


/*
 * processor0_0_timer configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_timer altera_avalon_timer
#define PROCESSOR0_0_TIMER_ALWAYS_RUN 0
#define PROCESSOR0_0_TIMER_BASE 0x8001020
#define PROCESSOR0_0_TIMER_COUNTER_SIZE 32
#define PROCESSOR0_0_TIMER_FIXED_PERIOD 0
#define PROCESSOR0_0_TIMER_FREQ 50000000
#define PROCESSOR0_0_TIMER_IRQ 0
#define PROCESSOR0_0_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PROCESSOR0_0_TIMER_LOAD_VALUE 499999
#define PROCESSOR0_0_TIMER_MULT 0.0010
#define PROCESSOR0_0_TIMER_NAME "/dev/processor0_0_timer"
#define PROCESSOR0_0_TIMER_PERIOD 10
#define PROCESSOR0_0_TIMER_PERIOD_UNITS "ms"
#define PROCESSOR0_0_TIMER_RESET_OUTPUT 0
#define PROCESSOR0_0_TIMER_SNAPSHOT 1
#define PROCESSOR0_0_TIMER_SPAN 32
#define PROCESSOR0_0_TIMER_TICKS_PER_SEC 100.0
#define PROCESSOR0_0_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define PROCESSOR0_0_TIMER_TYPE "altera_avalon_timer"


/*
 * processor0_0_timestamp configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_timestamp altera_avalon_timer
#define PROCESSOR0_0_TIMESTAMP_ALWAYS_RUN 0
#define PROCESSOR0_0_TIMESTAMP_BASE 0x8000000
#define PROCESSOR0_0_TIMESTAMP_COUNTER_SIZE 64
#define PROCESSOR0_0_TIMESTAMP_FIXED_PERIOD 0
#define PROCESSOR0_0_TIMESTAMP_FREQ 50000000
#define PROCESSOR0_0_TIMESTAMP_IRQ -1
#define PROCESSOR0_0_TIMESTAMP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSOR0_0_TIMESTAMP_LOAD_VALUE 49999
#define PROCESSOR0_0_TIMESTAMP_MULT 0.0010
#define PROCESSOR0_0_TIMESTAMP_NAME "/dev/processor0_0_timestamp"
#define PROCESSOR0_0_TIMESTAMP_PERIOD 1
#define PROCESSOR0_0_TIMESTAMP_PERIOD_UNITS "ms"
#define PROCESSOR0_0_TIMESTAMP_RESET_OUTPUT 0
#define PROCESSOR0_0_TIMESTAMP_SNAPSHOT 1
#define PROCESSOR0_0_TIMESTAMP_SPAN 64
#define PROCESSOR0_0_TIMESTAMP_TICKS_PER_SEC 1000.0
#define PROCESSOR0_0_TIMESTAMP_TIMEOUT_PULSE_OUTPUT 0
#define PROCESSOR0_0_TIMESTAMP_TYPE "altera_avalon_timer"


/*
 * processor0_0_utlb_0 configuration
 *
 */

#define ALT_MODULE_CLASS_processor0_0_utlb_0 utlb
#define PROCESSOR0_0_UTLB_0_BASE 0x8300000
#define PROCESSOR0_0_UTLB_0_IRQ -1
#define PROCESSOR0_0_UTLB_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSOR0_0_UTLB_0_NAME "/dev/processor0_0_utlb_0"
#define PROCESSOR0_0_UTLB_0_SPAN 1024
#define PROCESSOR0_0_UTLB_0_TYPE "utlb"


/*
 * processor1_0_cpu_irq_0 configuration
 *
 */

#define ALT_MODULE_CLASS_processor1_0_cpu_irq_0 cpu_irq
#define PROCESSOR1_0_CPU_IRQ_0_BASE 0x2200400
#define PROCESSOR1_0_CPU_IRQ_0_IRQ -1
#define PROCESSOR1_0_CPU_IRQ_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSOR1_0_CPU_IRQ_0_NAME "/dev/processor1_0_cpu_irq_0"
#define PROCESSOR1_0_CPU_IRQ_0_SPAN 1024
#define PROCESSOR1_0_CPU_IRQ_0_TYPE "cpu_irq"


/*
 * processorM_0_cpu_irq_0 configuration
 *
 */

#define ALT_MODULE_CLASS_processorM_0_cpu_irq_0 cpu_irq
#define PROCESSORM_0_CPU_IRQ_0_BASE 0x2200800
#define PROCESSORM_0_CPU_IRQ_0_IRQ -1
#define PROCESSORM_0_CPU_IRQ_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PROCESSORM_0_CPU_IRQ_0_NAME "/dev/processorM_0_cpu_irq_0"
#define PROCESSORM_0_CPU_IRQ_0_SPAN 1024
#define PROCESSORM_0_CPU_IRQ_0_TYPE "cpu_irq"


/*
 * shared_memory configuration
 *
 */

#define ALT_MODULE_CLASS_shared_memory altera_avalon_onchip_memory2
#define SHARED_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define SHARED_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define SHARED_MEMORY_BASE 0x2500000
#define SHARED_MEMORY_CONTENTS_INFO ""
#define SHARED_MEMORY_DUAL_PORT 0
#define SHARED_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define SHARED_MEMORY_INIT_CONTENTS_FILE "nios_fprint_shared_memory"
#define SHARED_MEMORY_INIT_MEM_CONTENT 1
#define SHARED_MEMORY_INSTANCE_ID "NONE"
#define SHARED_MEMORY_IRQ -1
#define SHARED_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SHARED_MEMORY_NAME "/dev/shared_memory"
#define SHARED_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define SHARED_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define SHARED_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define SHARED_MEMORY_SINGLE_CLOCK_OP 0
#define SHARED_MEMORY_SIZE_MULTIPLE 1
#define SHARED_MEMORY_SIZE_VALUE 1024
#define SHARED_MEMORY_SPAN 1024
#define SHARED_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define SHARED_MEMORY_WRITABLE 1


/*
 * sys_id configuration
 *
 */

#define ALT_MODULE_CLASS_sys_id altera_avalon_sysid_qsys
#define SYS_ID_BASE 0x1001020
#define SYS_ID_ID 0
#define SYS_ID_IRQ -1
#define SYS_ID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYS_ID_NAME "/dev/sys_id"
#define SYS_ID_SPAN 8
#define SYS_ID_TIMESTAMP 1417446642
#define SYS_ID_TYPE "altera_avalon_sysid_qsys"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC PROCESSOR0_0_TIMER_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0

#endif /* __SYSTEM_H_ */
