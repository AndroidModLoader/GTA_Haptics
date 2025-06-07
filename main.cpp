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

/* Functions (Pointers) */
void* (*FindPlayerPed)(int);

/* Functions */
void DoVibroBasedOnDamage(float dmg)
{
    aml->DoVibro( 20 );
}

/* Hooks */
DECL_HOOKb(GenerateDamageEvent, void *pHitPed, void *pEntity, int WeaponType, int WeaponDamage, int PieceType, int dir)
{
    if(GenerateDamageEvent(pHitPed, pEntity, WeaponType, WeaponDamage, PieceType, dir))
    {
        void* focusPlayer = FindPlayerPed(-1);
        if(pEntity == focusPlayer) DoVibroBasedOnDamage( WeaponDamage );
        return true;
    }
    return false;
}

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

    /* Funcies */
    if(hGTASA)
    {
        SET_TO(FindPlayerPed, aml->GetSym(hGTASA, "_Z13FindPlayerPedi"));
    }

    /* Hookies */
    if(pGTASA)
    {
        HOOK(GenerateDamageEvent, aml->GetSym(hGTASA, "_ZN7CWeapon19GenerateDamageEventEP4CPedP7CEntity11eWeaponTypei14ePedPieceTypesi"));
    }
}