class CfgPatches
{
	class ZenZippo
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Cooking"
		};
	};
};

class CfgMods
{
	class ZenZippo
	{
		dir = "ZenZippo";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenZippo";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenZippo/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenZippo/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenZippo/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class PetrolLighter;

	// Vanilla Petrol lighter EnergyManager config
	class ZenPetrolLighter: PetrolLighter
	{
		varQuantityMin=0;
		varQuantityMax=900; 
		varQuantityInit=900;
		varQuantityDestroyOnMin=0;
		weightPerQuantityUnit=0;
		class EnergyManager
		{
			autoSwitchOff=1;
			energyAtSpawn=900; // 15 mins burn time
			energyStorageMax=900;
			energyUsagePerSecond=1;
			updateInterval=1;
			convertEnergyToQuantity=1;
			autoSwitchOffWhenInCargo=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class LighterZippo
				{
					soundSet=""; // Mute action SFX as lighter is lit
					id=201;
				};
			};
		};
	};

	// My zippos
	class ZenZippoLighter: ZenPetrolLighter
	{
		scope=2;
		displayName="$STR_CfgVehicles_ZenZippoLighter0";
		descriptionShort="$STR_CfgVehicles_ZenZippoLighter1";
		model="ZenZippo\data\zippo\zippo.p3d";
		rotationFlags=17;
		isMeleeWeapon=1;
		canBeSplit=0;
		absorbency=0;
		weight=50;
		itemSize[]={1,1};
		stackedUnit="ml";
		quantityBar=1;
		varQuantityMin=0;
		varQuantityMax=1800;
		varQuantityInit=1800;
		varQuantityDestroyOnMin=0;
		varTotalLifetime=7200; // How many seconds does this zippo work for before ruining from Pristine?
		weightPerQuantityUnit=0;
		simpleHiddenSelections[]= 
		{
			"top_open",
			"top_closed"
	    };
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenZippo\data\zippo\zippo_co.paa" };
		class EnergyManager
		{
			autoSwitchOff=1;
			energyAtSpawn=1800; // 30 mins burn time
			energyStorageMax=1800;
			energyUsagePerSecond=1;
			updateInterval=1;
			convertEnergyToQuantity=1;
			autoSwitchOffWhenInCargo=1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZenZippo\data\zippo\zippo.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZenZippo\data\zippo\zippo.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZenZippo\data\zippo\zippo_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZenZippo\data\zippo\zippo_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZenZippo\data\zippo\zippo_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class LighterZippo
				{
					soundSet=""; // Mute action SFX as lighter is lit
					id=201;
				};
			};
		};
		soundImpactType="metal";
	};
	class ZenZippoLighter_Peace: ZenZippoLighter
	{
		hiddenSelectionsTextures[] = { "ZenZippo\data\zippo\zippo_peace_co.paa" };
	};
	class ZenZippoLighter_Anarchy: ZenZippoLighter
	{
		hiddenSelectionsTextures[] = { "ZenZippo\data\zippo\zippo_anarchy_co.paa" };
	};
	class ZenZippoLighter_Zenarchist: ZenZippoLighter
	{
		hiddenSelectionsTextures[] = { "ZenZippo\data\zippo\zippo_zenarchist_co.paa" };
	};
}