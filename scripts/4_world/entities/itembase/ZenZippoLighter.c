class ZenZippoLighter extends PetrolLighter
{
	// Turn off after server restart/login
	override void DeferredInit()
	{
		super.DeferredInit();

		if (GetCompEM() && GetCompEM().IsWorking())
			GetCompEM().SwitchOff();
	}

	// Show/hide components from P3D listed as 'sections' in model.cfg (ie. lighter lid)
	protected void ZippoShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections", selectionNames);

		if (!selectionNames)
			return;

        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    }

	//! CLIENT
	override void StartLighterFX()
	{
		ZippoShowSimpleSelection("top_closed", 0);
		ZippoShowSimpleSelection("top_open", 1);

		if (GetGame().IsClient())
		{
			PlaySoundSet(m_LighterStartSound, START_SOUND, 0, 0);
			UpdateLight();

			if (!m_FireParticle)
				m_FireParticle = Particle.PlayOnObject(ParticleList.ZEN_ZIPPO_FLAME, this, GetMemoryPointPos("flame"), Vector(0,0,0), true);

			m_FireParticle.SetWiggle(3, 0.1);
		}
	}

	//! CLIENT
	override void StopLighterFX()
	{
		ZippoShowSimpleSelection("top_closed", 1);
		ZippoShowSimpleSelection("top_open", 0);

		if (GetGame().IsClient())
		{
			if (m_Light)
				m_Light.FadeOut();

			if (m_FireParticle)
				m_FireParticle.Stop();
		}
	}

	override bool StopLighterOnGround()
	{
		return false;
	}

	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);

		#ifdef SERVER
		float dmg = (GetMaxHealth() / ConfigGetInt("varTotalLifetime")) * -1;
		AddHealth(dmg); // Damage lighter slowly over time since it's refillable.
		#endif
	}
}
