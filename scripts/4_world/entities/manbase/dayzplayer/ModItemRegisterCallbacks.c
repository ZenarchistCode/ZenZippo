modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);

		pType.AddItemInHandsProfileIK("ZenZippoLighter", "dz/anims/workspaces/player/player_main/props/player_main_1h_lighter.asi", pBehavior,	"dz/anims/anm/player/ik/gear/petrol_lighter.anm");
	}
}