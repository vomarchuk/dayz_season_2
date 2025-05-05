class CampMission extends SurvivorMissions
{
	//Mission related entities 
	TentBase MissionObject;
	FireplaceBase MissionCampfire;
	Object cc_fireplace;
	Object cc_mtent;
	Grenade_Base BoobyTrap; 
	
	//Mission parameters
	int MsgDlyFinish = 300;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return false;
	
	void CampMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 170.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Виживший";
	
		//Mission person names
		TStringArray SurvivorNames = {"Юрій", "Михайло", "Борис", "валерій", "Анатолій", "Степан", "Олексій", "Дмитро", "Сергій", "Микола" };
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages
        // m_MissionMessage1 = "My friend "+ SurvivorName +" hasn't responded on the radio for last 2 hours. He is an excellent outdoor survivor and im wondering if he's ok.";
        // m_MissionMessage2 = "His daughter is infected,  He looks after her sometimes. About 5 hours ago, he told me that he has found  stuff in some houses of "+ m_MissionLocation +" and was attacked on the way back to his camp but wasn't injured.";
        // m_MissionMessage3 = "I think he said that he recently pitched up his tent\n "+ m_MissionLocationDir +" of "+ m_MissionLocation +" \nI am very worried, I would really appreciate it if you could go look after him. Be-Careful, he uses traps to protect his place!";		
				
		m_MissionMessage1 = "Мій друг " + SurvivorName + " мовчить по рації вже понад 2 години. Він добре знає, як виживати, але я непокоюся.";
		m_MissionMessage2 = "Його дочка заражена, він іноді піклується про неї. Востаннє казав, що шукав припаси поблизу " + m_MissionLocation + " і був атакований дорогою назад.";
		m_MissionMessage3 = "Він ставив намет" + m_MissionLocationDir + " від " + m_MissionLocation + "\n**Можеш перевірити, чи з ним усе добре? Але остерігайся пасток!";


		//Infected spawnpoints
		InfectedSpawns.Insert("-10.5186 0 25.0269");
		InfectedSpawns.Insert("24.9775 0 -10.4146");
		InfectedSpawns.Insert("-30.1726 0 -6.2729");
		InfectedSpawns.Insert("-20.9209 0 4.6636");
		InfectedSpawns.Insert("15.0283 0 -10.3276");
		InfectedSpawns.Insert("7.2461 0 30.5884");
		InfectedSpawns.Insert("-20.6855 0 5.9956");
		
		//Infected types
		//Male												//Female
		InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");	InfectedTypes.Insert("ZmbF_JournalistNormal_White");
		InfectedTypes.Insert("ZmbM_priestPopSkinny");		InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
		InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");	InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Red");		InfectedTypes.Insert("ZmbF_CitizenBSkinny");
		InfectedTypes.Insert("ZmbM_FishermanOld_Green");	InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
		InfectedTypes.Insert("ZmbM_HunterOld_Autumn");		InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");		InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
		InfectedTypes.Insert("ZmbM_MotobikerFat_Black");	InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");		InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");	InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
		InfectedTypes.Insert("ZmbM_HandymanNormal_Green");	InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
		InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");	InfectedTypes.Insert("ZmbF_PatientOld");
		InfectedTypes.Insert("ZmbM_Jacket_black");			InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
		InfectedTypes.Insert("ZmbM_Jacket_stripes");		InfectedTypes.Insert("ZmbF_VillagerOld_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");	InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
		InfectedTypes.Insert("ZmbM_PolicemanFat");			InfectedTypes.Insert("ZmbF_VillagerOld_Green");
		InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");	InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");		InfectedTypes.Insert("ZmbF_NurseFat");
		InfectedTypes.Insert("ZmbM_VillagerOld_White");		InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
		InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");		InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");	InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
		InfectedTypes.Insert("ZmbM_DoctorFat");				InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
		InfectedTypes.Insert("ZmbM_PatientSkinny");			InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
		InfectedTypes.Insert("ZmbM_ClerkFat_Brown");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
		InfectedTypes.Insert("ZmbM_ClerkFat_White");		InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
		InfectedTypes.Insert("ZmbM_Jacket_magenta");		InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
		InfectedTypes.Insert("ZmbM_PolicemanSpecForce");	InfectedTypes.Insert("ZmbF_DoctorSkinny");
	}
	
	void ~CampMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else
				{
					//Delete Object clientside first
					if ( m_MissionObjects.Get(i).GetType() == "ClutterCutterFireplace" )
					GetGame().RemoteObjectDelete( m_MissionObjects.Get(i) );				
					
					//Delete Object serverside
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );
				}		
			}
			m_MissionObjects.Clear();
		}
		
		//Despawn mission AI's
		if ( m_MissionAIs )
		{
			if ( m_MissionAIs.Count() > 0 )
			{
				Print("[SMM] Despawning "+ m_MissionAIs.Count() +" mission AI's from old mission...");
				for ( int k = 0; k < m_MissionAIs.Count(); k++ )
				{
					GetGame().ObjectDelete( m_MissionAIs.Get(k) );
				}
				m_MissionAIs.Clear();			
			}
			else Print("[SMM] No mission AI's to despawn.");
		}
		
		//Delete PlayersInZone list & reset container takeaway
		if ( m_PlayersInZone )	m_PlayersInZone.Clear();
		if ( m_ContainerWasTaken ) m_ContainerWasTaken = false;
	}
	
	void SpawnObjects()
	{				
		//Clean up place from droped items before new tent spawns 
		bool ItemsAtGround = false; 
		
		GetGame().GetObjectsAtPosition( m_MissionPosition , 4.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.IsItemBase() )
			{
				ItemsAtGround = true;
				Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");				
				GetGame().ObjectDelete( FoundObject );
			}
		}
		//...and in case move tent pos a bit
		if ( ItemsAtGround )
		{
			float x = Math.RandomFloatInclusive( 1.5 , 3.0 );
			float y = Math.RandomFloatInclusive( 1.5 , 3.0 );
			int Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice > 4 ) x *= -1.0;
			Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice < 5 ) y *= -1.0;
			vector NewPosVector = { x, 0, y };
			m_MissionPosition += NewPosVector;
			Print("[SMM] BeforeSpawnCleanUp :: Items on the ground detected. Tent position predictively was moved a bit.");
		}
		
		//Spawn & pitch tent		
		MissionObject = TentBase.Cast( GetGame().CreateObject( "MediumTent", m_MissionPosition ) );
		MissionObject.Pitch( true , true );
		MissionObject.PlaceOnSurface();
		
		ref array<string> randomItems = RandomItemsList.GetItems();
		int m_rewards = 3;



		//Get random loadout 			
		int selectedLoadout = Math.RandomIntInclusive(3,11);	//!Change randomization limit after adding new loadouts!
		
		//Spawn selected loadout items in mission object
		EntityAI weapon;
								
		if (selectedLoadout == 0)
		{
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 1)
		{
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x54Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 2)
		{
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 3)
		{
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 4)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

				
		}
		if (selectedLoadout == 5)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}	
		if (selectedLoadout == 6)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}
		if (selectedLoadout == 7)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}
		if (selectedLoadout == 8)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			
		}
		if (selectedLoadout == 9)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		
		}

		if (selectedLoadout == 10)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
	
		}
		if (selectedLoadout == 11)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}

		array<string> availableItems = randomItems; 

		for (int j = 0; j < m_rewards && availableItems.Count() > 0; j++) 
		{
			int randomIndex = Math.RandomInt(0, availableItems.Count()); 
			string randomItem = availableItems.Get(randomIndex);
			
			if (MissionObject.GetInventory().CreateInInventory(randomItem))
			{
				Print("[SMM] Добавлен предмет: " + randomItem);
				availableItems.Remove(randomIndex); 
			}
			else
			{
				Print("[SMM] Ошибка добавления предмета: " + randomItem);
			}
		}
		
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was " + selectedLoadout + ".");
		
	
		//Insert mission tent into mission objects list
		m_MissionObjects.Insert( MissionObject );
	
		//Clutter Cutter Tent 	
		cc_mtent = GetGame().CreateObject( "MediumTentClutterCutter" , MissionObject.GetPosition() , false );
		cc_mtent.SetOrientation( MissionObject.GetOrientation() );
		GetGame().RemoteObjectCreate( cc_mtent );		 
		m_MissionObjects.Insert( cc_mtent );
		
		//Fireplace
		vector CampfirePosition;
		vector CampfireOrientation;
		vector CampFireDir = MissionObject.GetOrientation();
		float CampFireDist = 4;
			
		GetGame().ObjectDelete( cc_fireplace );
		GetGame().ObjectDelete( MissionCampfire );
		if ( CampFireDir[0] < 0 )	CampFireDir[0] = 360 + CampFireDir[0];
		//some nostalgic code 
		CampfirePosition [0] = m_MissionPosition [0] - Math.Sin( CampFireDir[0] * Math.DEG2RAD ) * CampFireDist;		//x offset
		CampfirePosition [2] = m_MissionPosition [2] - Math.Cos( CampFireDir[0] * Math.DEG2RAD ) * CampFireDist;		//y offset
		MissionCampfire = FireplaceBase.Cast( GetGame().CreateObject( "Fireplace", CampfirePosition ) );
		CampfireOrientation = MissionCampfire.GetOrientation();
		MissionCampfire.Synchronize();
		MissionCampfire.GetInventory().CreateAttachment("Firewood");
		MissionCampfire.GetInventory().CreateAttachment("WoodenStick");
		MissionCampfire.GetInventory().CreateAttachment("Rag");
		MissionCampfire.GetInventory().CreateAttachment("Stone");
		MissionCampfire.StartFire( true );
		m_MissionObjects.Insert( MissionCampfire );
		
		//Cluttercutter fireplace
		cc_fireplace = GetGame().CreateObject( "ClutterCutterFireplace" , MissionCampfire.GetPosition() );
		cc_fireplace.SetOrientation( CampfireOrientation );
		GetGame().RemoteObjectCreate( cc_fireplace );
		m_MissionObjects.Insert( cc_fireplace );
							
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}
	
	void SpawnAIs()
	{	
		//Spawn dead infected
		vector InfectedPos = MissionObject.ModelToWorld( "0 0 -6" );
		m_MissionAIs.Insert( GetGame().CreateObject( "ZmbM_HikerSkinny_Blue" , InfectedPos , false , true ) );
		DayZInfected InfectedSurvivor = DayZInfected.Cast( m_MissionAIs[0] );
			InfectedSurvivor.GetInventory().CreateAttachment("FlatCap_Blue");
			InfectedSurvivor.GetInventory().CreateAttachment("MountainBag_Blue");
			InfectedSurvivor.GetInventory().CreateInInventory("CanOpener");
			InfectedSurvivor.GetInventory().CreateInInventory("PeachesCan");
			InfectedSurvivor.GetInventory().CreateInInventory("Canteen");
			InfectedSurvivor.GetInventory().CreateInInventory("Battery9V");
				
			InfectedSurvivor.SetHealth("","",0);
		
		//Spawn boobytraped infected
		string RandomInfected = InfectedTypes.GetRandomElement();
		vector InfectedPos1 = MissionObject.ModelToWorld( "0 0 5" );
		
		m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos1, false, true ) );
		BoobyTrap = Grenade_Base.Cast( GetGame().CreateObject( "M67Grenade" , InfectedPos1, false, false, false ));
		BoobyTrap.ActivateImmediate();
		
		
		//Spawn infected
		for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
		{
    	   	RandomInfected = InfectedTypes.GetRandomElement();
			InfectedPos1 = MissionObject.ModelToWorld( InfectedSpawns.Get(j) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos1, false, true ) );
		}	
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			//Exception: Fireplace & ClutterCutterFireplace will remain
			if ( m_MissionObjects.Get(i).GetType() == "Fireplace" || m_MissionObjects.Get(i).GetType() == "ClutterCutterFireplace" )	
			{
				Print("[SMM] "+ m_MissionObjects.Get(i).GetType() +" was excluded from pre-deletion.");
				continue;
			}
			
			//Delete Object clientside first
			if ( m_MissionObjects.Get(i).GetType() == "MediumTentClutterCutter" ) GetGame().RemoteObjectDelete( m_MissionObjects.Get(i) );
			
			//Delete Object serverside
			GetGame().ObjectDelete( m_MissionObjects.Get(i) );
		}
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone	
		//Respawn some infected 
		for ( int j = 0 ; j < 2 ; j++ )
		{
    	   	string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos = MissionObject.ModelToWorld( InfectedSpawns.GetRandomElement() );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );			
		}

		//Finish mission
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;			
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway )
		{		
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "MediumTent" ) 
			{
				if ( TentBase.Cast( m_MissionObjects[0] ).CanBeManipulated() && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission tent was packed by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}	
	}
		
	void UpdateBots(float dt)
	{
		//Test1.OnUpdate(dt);		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		if ( m_MissionPosition && m_MissionPosition != "0 0 0" )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
			return false;
		}
	}
}

