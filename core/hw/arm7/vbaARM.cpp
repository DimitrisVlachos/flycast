// nullAICA.cpp : Defines the entry point for the DLL application.
//

#include "types.h"
#include "arm7.h"
#include "arm_mem.h"


//called when plugin is used by emu (you should do first time init here)
s32 libARM_Init()
{
	arm_Init();

	return 0;
}

//called when plugin is unloaded by emu, only if dcInit is called (eg, not called to enumerate plugins)
void libARM_Term()
{
	//arm7_Term ?
}

//It's supposed to reset anything
void libARM_Reset(bool Manual)
{
	arm_Reset();
	arm_SetEnabled(false);
}

void libARM_SetResetState(u32 state)
{
	arm_SetEnabled(state==0);
}

//Mainloop
void libARM_Update(u32 Cycles)
{
	arm_Run(Cycles/arm_sh4_bias);
}
