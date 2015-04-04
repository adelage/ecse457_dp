/*
 * shared_mem.h
 *
 *  Created on: 2013-11-08
 *      Author: Jonah
 */

#ifndef SHARED_MEM_H_
#define SHARED_MEM_H_

// Definitions
 #define NUM_CORES 2


typedef struct CriticalFunctionPointers{
	//Priority of the critical task
	unsigned int priority[NUM_CORES];
	//The pointer to the function code
	void *task[NUM_CORES];
	//Arguments to the function
	void *args[NUM_CORES];
	//To pass timing results back from the cores to the monitor
	alt_u64  core_time[NUM_CORES];
	//Monitor signals to cores to begin initializing in main
	int init_complete;
	//Cores signal that they are done
	int core_ready[NUM_CORES];
	//Cores signal to each other that they are ready
	int checkout[NUM_CORES];
	//Cores find out who their partner is
	int partner[NUM_CORES];
	//blocksize for fingerprinting
	int blocksize[NUM_CORES];

}CriticalFunctionPointers;


#endif /* SHARED_MEM_H_ */
