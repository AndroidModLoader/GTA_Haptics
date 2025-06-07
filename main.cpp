#include <mod/amlmod.h>
#include <mod/logger.h>
#include <isautils.h>

MYMOD(net.rusjj.ghaptics, GHaptics, 1.0, RusJJ)
NEEDGAME(com.rockstargames.gtasa)
BEGIN_DEPLIST()
    ADD_DEPENDENCY_VER(net.rusjj.aml, 1.3)
END_DEPLIST()

/* Saves */
void *hGTASA, *hGTAVC;
uintptr_t pGTASA, pGTAVC;
ISAUtils* sautils;

/* Main */
extern "C" void OnAllModsLoaded()
{
    /* Logging */
    logger->SetTag("GHaptics");

    /* Libraries'n'Stuff */
    hGTASA = aml->GetLibHandle("libGTASA.so");
    hGTAVC = aml->GetLibHandle("libGTAVC.so");
    pGTASA = aml->GetLib("libGTASA.so");
    pGTAVC = aml->GetLib("libGTAVC.so");
    sautils = (ISAUtils*)GetInterface("SAUtils");
    if(sautils)
    {
        
    }

    /* Hookies */
    
}