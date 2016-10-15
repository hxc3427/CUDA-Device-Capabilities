#include <cstdlib> // malloc(), free()
#include <iostream> // cout, stream
#include <stdio.h>
#include <cuda_runtime_api.h>
#include "common.h"
// Entry point for the program.
bool checkForError( cudaError_t error);

int main()
{
	bool checkForError();

	printf("CUDA DEVICE CAPABILITIES\n\n\n");

	int device_count,driverVersion,runtimeVersion,i;

/////DEVICE COUNT//////////////////////////////////////////////
	cudaError_t error1 = cudaGetDeviceCount(&device_count);
	if (error1 != cudaSuccess){ 
		printf("%s\n",cudaGetErrorString(error1));
	}
    printf("No. OF cuda Devices are %d\n",device_count);
////....................................................../////
	for (int i = 0; i < device_count; i++) {
///////////CUDA DRIVER VERSION//////////////////////////
	cudaError_t error2 = cudaDriverGetVersion(&driverVersion);
	if (error2 != cudaSuccess){ 
		printf("%s\n",cudaGetErrorString(error2));
	}
    printf("CUDA driver Version are %d\n",driverVersion);
//...........................................................//

	cudaError_t error3 = cudaRuntimeGetVersion(&runtimeVersion);
	if (error3 != cudaSuccess){ 
		printf("%s\n",cudaGetErrorString(error3));
	}
	printf("cuda runtimeVersion are %d \n\n",runtimeVersion);

//////////////CUDA DEVICE PROPERTIES///////////////////////
	cudaDeviceProp prop;
    cudaError_t error4 =  cudaGetDeviceProperties(&prop,i);
	if (error4 != cudaSuccess){ 
		printf("%s\n",cudaGetErrorString(error4));
	}
	printf("Device Number: %d\n\n", i);
    printf("Device name: %s", prop.name);
	if (prop.integrated==1){
		printf("  (Integrated)\n");
	}
	else{
		printf("  (Discreete)\n");
	}
	printf("CUDA Capabilities %d.%d\n\n",prop.major,prop.minor);
    
	/////////////////////////////PROCESSOR///////////
printf("PROCESSING:\n");

printf("       Multi-Processor Count: %d\n",prop.multiProcessorCount);
printf("       Max Grid Size: %d X %d X %d\n",prop.maxGridSize[0],prop.maxGridSize[1],prop.maxGridSize[2]);
printf("       Max Block Size: %d X %d X %d\n",prop.maxThreadsDim[0],prop.maxThreadsDim[1],prop.maxThreadsDim[2]);
printf("       Max Threads Per Block: %d\n",prop.maxThreadsPerBlock);
printf("       Max Threads Per Multi-Processor: %d\n",prop.maxThreadsPerMultiProcessor);
printf("       Warp Size: %d\n",prop.warpSize);
printf("       Clock Rate: %f GHz\n",float(prop.clockRate)/1000000);
	
	
///.............................................//////////////
printf("Memory:\n");

printf("       Global: %d MB\n",prop.totalGlobalMem/(1024*1024));
printf("       Constant: %d KB\n",prop.totalConstMem/1024);
printf("       Shared/BLK: %d KB\n",prop.sharedMemPerBlock/1024);
printf("       Registers/BLK: %d\n",prop.regsPerBlock);
printf("       Maximum Pitch: %d MB\n",prop.memPitch/(1024*1024));
printf("       Texture Alignment: %d B\n",prop.textureAlignment);
printf("       L2 Cache Size: %d B\n",prop.l2CacheSize);
printf("       Memory Clock Rate: %f MHz\n",float(prop.memoryClockRate)/1000);
//printf("       Memory Bus Width: %d bits\n",prop.memoryBusWidth);
//printf("       Peak Memory Bandwidth: %f GB/s\n",2.0*prop.memoryClockRate*(prop.memoryBusWidth/8)/1.0e6);
	
	
	
	
    
	
	
	//textureAlignment
    //printf("  textureAlignment: %d\n",prop.textureAlignmentm);
   
/////////////////////////////////////////////////////
	if (prop.concurrentKernels==1){
		printf("Concurrent Kernels Execution: No\n");
	}
	else{
		printf("Concurrent Kernels Execution: YES\n");
	}
/////////////////////////////////////////////////
if (prop.kernelExecTimeoutEnabled==1){
		printf("Kernel time limit: YES\n");
	}
	else{
		printf("Kernel time limit: NO\n");
	}
//////////////////////////////////////////
	if (prop.canMapHostMemory==1){
		printf("Supports Page-Locked Memory Mapping: YES\n");
	}
	else{
		printf("Supports Page-Locked Memory Mapping: NO\n");
	}
////////////////////////////////////////////
	if (prop.computeMode==0){
		printf("Compute Mode: Default\n");
	}
	else{
		printf("Compute Mode: Exclusive\n");
	}
////////////////////////////////////////////	
	/*if (prop.ECCEnabled==1){
		printf("ECC Enabled: YES\n");
	}
	else{
		printf("ECC Enabled: NO\n");
	}*/
///////////////////////////////////////////////    
//	printf("       pciBusID: %d\n",prop.pciBusID);
	//printf("       pciDeviceID: %d\n",prop.pciDeviceID);
	//printf("       tccDriver: %d\n",prop. tccDriver);
////////////////////////////////////////////////////
	
	//cudaGetDeviceProperties(struct cudaDeviceProp* prop, int device);
    //Keep the error status
    //cudaError_t status;
	printf("//////////////////////////////////////////////////////////////////////////////\n");
	}
	getchar();
    return 0;
}

bool checkForError(){
	int devices;
	
	cudaError_t status= cudaGetDeviceCount(&devices);
	if (status != cudaSuccess){ 
		printf("cudaGetErrorString(status)");
		return 0;
	}
		else{
		printf("CUDA API CALL SUCCESS\n\n");
	}
}