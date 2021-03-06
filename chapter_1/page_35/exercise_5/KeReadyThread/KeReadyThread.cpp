VOID NTAPI KeReadyThread(
    IN PKTHREAD 	Thread
)
{
    KIRQL irql = KeAcquireQueuedSpinLockRaiseToSynch(0);
    KiReadyThread(Thread);
    KeReleaseQueuedSpinLockFromDpcLevel(fs:[20h] + 0x418h);
    KiExitDispatcher(irql);
}