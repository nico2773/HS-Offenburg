#include "Consumer.h"
#include "Producer.h"
#include <ostream>
#define _CRTDBG_MAP_ALLOC

void vTestCreateObjects(void);
int main(void)
{
	vTestCreateObjects();
	_CrtDumpMemoryLeaks();
	return 0;
}


void vTestCreateObjects(void)
{
	int32_t i32Var = 4;
	MyDataStructures::Ringbuffer* pRP = new MyDataStructures::Ringbuffer(10U);
	Client::Consumer* pCon = new Client::Consumer(pRP);
	Client::Producer sPro(pRP);
	pRP->vPrintRingBuffer();
	for (int i = 0; i < 5; i++)
	{
		sPro.s32WriteToRingbuffer(i);
	}

	pCon->s32ReadFromRingbuffer(i32Var);
	pRP->vPrintRingBuffer();


}