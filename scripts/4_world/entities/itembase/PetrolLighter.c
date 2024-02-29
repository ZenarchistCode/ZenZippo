modded class PetrolLighter
{
	static const string START_SOUND = "Lighter_Soundset";

	protected ZenZippoLight m_Light;
	protected Particle m_FireParticle;
	protected EffectSound m_LighterStartSound;
	protected EffectSound m_LighterStopSound;
	protected bool m_IsLitClient;

	// Set lighter to off state on creation
	void PetrolLighter()
	{
		StopLighterFX();
	}

	// Set lighter to off state on despawn
	void ~PetrolLighter()
	{
		StopLighterFX();
	}

	//! CLIENT
	void StartLighterFX()
	{
		PlaySoundSet(m_LighterStartSound, START_SOUND, 0, 0);
		UpdateLight();

		if (!m_FireParticle)
			m_FireParticle = Particle.PlayOnObject(ParticleList.ZEN_ZIPPO_FLAME, this, Vector(0,0.02,0), Vector(0,0,0), true);

		m_FireParticle.SetWiggle(3, 0.1);
	}

	//! CLIENT
	void StopLighterFX()
	{
		if (m_Light)
			m_Light.FadeOut();

		if (m_FireParticle)
			m_FireParticle.Stop();
	}

	bool StopLighterOnGround()
	{
		return true;
	}

	// Turn off if moved out of hands
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);

		if (StopLighterOnGround() && newLoc.GetType() != InventoryLocationType.HANDS)
		{
			if (GetCompEM() && GetCompEM().IsWorking())
				GetCompEM().SwitchOff();
		}
	}

	// Turn off after server restart
	override void EEOnAfterLoad()
	{
		super.EEOnAfterLoad();

		if (GetCompEM() && GetCompEM().IsWorking())
			GetCompEM().SwitchOff();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		// Sync visual fx
		if (!GetCompEM().IsWorking())
		{
			if (m_IsLitClient)
			{
				m_IsLitClient = false;
				StopLighterFX();
			}
		}
		else 
		{
			if (!m_IsLitClient)
			{
				m_IsLitClient = true;
				StartLighterFX();
			}
		}
	}

	void UpdateLight()
	{
		if (!m_Light)
		{
			m_Light = ZenZippoLight.Cast(ScriptedLightBase.CreateLight(ZenZippoLight, Vector(0,0,0), 1));
			m_Light.AttachOnObject(this, Vector(0,0,0));
			m_Light.SetFadeOutTime(0.1);
		}

		if (m_FireParticle)
		{
			Object direct_particle = m_FireParticle.GetDirectParticleEffect();
			
			if (direct_particle && direct_particle != m_Light.GetAttachmentParent())
			{
				m_Light.AttachOnObject(direct_particle, Vector(0,0.1,0));
			}	
		}
	}

	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}

	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		if (IsIgnited())	
			return true;
		else
			return false;
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
}