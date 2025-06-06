class CityMallMission extends SurvivorMissions
{
	//Mission related entities 
	Car MissionCar;
	Object MissionBuilding;
	ItemBase MissionObject;
	ref TStringArray FoodTypes = {"SpaghettiCan","BakedBeansCan","SardinesCan","TunaCan","PeachesCan","TacticalBaconCan","Marmalade"};
	
	//Mission parameters
	int ReqFoodAmount = Math.RandomInt(7, 13);					//cans of food 
	int ReqMedAmount = Math.RandomInt(2, 7);						//packets of antibiotics
	int ExtendedTimout = 1800;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> MedSpawns = new array<vector>;
	ref array<vector> FoodSpawns = new array<vector>;
	ref array<vector> PriInfectSpawns = new array<vector>;
	ref array<vector> SecInfectSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	ref array<ref Param3<string,vector,vector>> Barricades = new array<ref Param3<string,vector,vector>>;
	
	//Mission variables 
	vector TargetPosition = "-5.3 -1.2 1.9";
	vector RewardsPosition = "-3.46 -5.72 6.63";
	string SurvivorName;	
	
	bool IsExtended() return true;
	
	void CityMallMission()
	{		
		//Select primary mission
		m_MissionExtended = true;
		
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, primary mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 100.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.7;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Лікар";
	
		//Mission person names
		TStringArray SurvivorNames = {"Тимаренко", "Лозинська", "Бласенко", "Гаварук", "Слоскова", "Білозір", "Хом’як", "Трембович", "Янковська"};

		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		// m_MissionMessage1 = "Ms. "+ SurvivorName +", a ground school teacher, told me that she has brought some children of her class in safety from their infected families. I promised that i will help her for getting food and other medical supplies for the kids.";
		// m_MissionMessage2 = "Yesterday I found out that the Supermarket in\n  "+ m_MissionLocation +"  \nis barricaded and probably has some food inside. But there were too many infected around, i wasn't able to check the Supermarket.";
		// m_MissionMessage3 = "She immediately needs following things from the market:\n- "+ ReqFoodAmount +" cans of food and..\n- "+ ReqMedAmount +" packets of antibiotics\nPlease help me to support Ms. "+ SurvivorName +" with those life essentials for the kids.";
		
		m_MissionMessage1 = "Пані " + SurvivorName + ", вчителька молодших класів, врятувала кількох дітей від заражених родичів. Я пообіцяв допомогти з їжею й ліками.";
		m_MissionMessage2 = "Схоже, у " + m_MissionLocation + " \n є забарикадований магазин з їжею, але заражених там було надто багато.";
		m_MissionMessage3 = "Їй терміново потрібно: " + ReqFoodAmount + " консервів " + ReqMedAmount + " упаковок антибіотиків\n Допоможи забезпечити дітей. І будь обережний.";


		//Spawnpoints for antibiotics in store (cash desk)
		MedSpawns.Insert("-5.392 -0.686 1.087");
		MedSpawns.Insert("-5.836 -0.686 1.087");
		MedSpawns.Insert("-5.865 -0.686 2.964");
		MedSpawns.Insert("-5.051 -0.686 3.033");
		MedSpawns.Insert("-5.092 -0.686 1.087");
				
		//Spawnpoints for food in store (shelves)
		FoodSpawns.Insert("10.9 0.061 0.019");
		FoodSpawns.Insert("10.9 0.061 0.857");
		FoodSpawns.Insert("10.9 0.061 2.525");
		FoodSpawns.Insert("10.9 0.061 3.195");
		FoodSpawns.Insert("10.9 -0.270 0.119");
		FoodSpawns.Insert("10.9 -0.621 0.219");
		FoodSpawns.Insert("10.5 0.061 0.019");
		FoodSpawns.Insert("10.5 -0.270 0.857");
		FoodSpawns.Insert("10.5 -0.621 2.525");
		FoodSpawns.Insert("10.5 0.061 3.195");				
				
		//Infected spawnpoints for primary mission
		//indoor
		PriInfectSpawns.Insert("-8.4 0 -1.2");	//dead
		PriInfectSpawns.Insert("-3.8 0 -1.3");	//dead
		PriInfectSpawns.Insert("-7.4 0 2");		//dead 
		PriInfectSpawns.Insert("12.2 0 1.5");
		PriInfectSpawns.Insert("10.5 0 -6.7");
		//outdoor
		PriInfectSpawns.Insert("-13.2 0 -6.5");
		PriInfectSpawns.Insert("-13.6 0 2.8");
		PriInfectSpawns.Insert("-8.57 0 7.3");
		PriInfectSpawns.Insert("-0.47 0 10.13");
		PriInfectSpawns.Insert("10.4 0 10");
		PriInfectSpawns.Insert("-7.5 0 -11");
		PriInfectSpawns.Insert("5.7 0 -12");
		
		//Infected spawnpoints for secondary mission 
		SecInfectSpawns.Insert("-3.3 0 -5.5");
		SecInfectSpawns.Insert("-2.9 0 -9");
		SecInfectSpawns.Insert("6.7 0 -7.2");
		SecInfectSpawns.Insert("8 0 4");
		
		//Infected types for primary and secondary mission position
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

		//Shop barricades  (view from inside building!)
		//shopwindow bottom line  (from right to left) 
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "11.24 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "9.98 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "8.72 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "7.46 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "6.2 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "4.94 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "3.68 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "2.42 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "1.16 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.1 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-1.36 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-2.62 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-3.88 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-5.14 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-6.4 -0.05 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "10.0 0.9 5.9", "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "7.0 0.9 5.9", "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "4.0 0.9 5.9", "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "1.0 0.9 5.9", "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "-2.0 0.9 5.9", "0 110 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Boat_Small1", "-5.0 0.9 5.9", "0 110 0"));
		//shopwindow top line  (from right to left)
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "11.24 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "9.98 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "8.72 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "7.46 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "6.2 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "4.94 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "3.68 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "2.42 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "1.16 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-0.1 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-1.36 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-2.62 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-3.88 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-5.14 1.21 5.97", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-6.4 1.21 5.97", "0 90 0"));
		//shopwindow small 
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.11 6.03", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.11 6.03", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-7.764 0.31 6.03", "180 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.642 0.31 6.03", "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.51 6.03", "180 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.51 6.03", "0 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.070 0.72 6.03", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.322 0.72 6.03", "180 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-8.370 0.93 6.03", "0 -90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-9.622 0.93 6.03", "180 -90 0"));				
		//shop entrance		
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.436 -0.602 4.070", "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.436 -0.602 2.810", "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.236 -0.602 1.560", "75 85 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.436 0.658 4.070", "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.436 0.658 2.810", "90 90 0"));
		Barricades.Insert( new Param3<string,vector,vector>("WoodenPlank", "-10.236 0.658 1.560", "75 95 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_Table", "-10.036 -0.252 4.070", "0 0 -90"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_Table", "-10.036 -0.252 2.970", "0 0 -90"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-10.0 -0.852 3.520", "0 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-9.69 -0.882 1.7", "-30 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "-9.59 -0.262 1.7", "-32 0 5"));
		//other stuff, dead survivor related 
		Barricades.Insert( new Param3<string,vector,vector>("AdvancedImprovisedShelterPitched", "7.84 -1.18149 1.39", "-90 0 0"));
		Barricades.Insert( new Param3<string,vector,vector>("PissGround", "-10.26 -1.21049 -8.08", "180 0 0"));
									
		//Search for mission building at primary mission position	
		GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_City_Store" )
			{	
				MissionBuilding = FoundObject;			 
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				break;
			}	
		}
		if ( !MissionBuilding ) Print("[SMM] City store couldn't be found. Mission rejected!");
		else
		{
			//Close all store doors
			Building Store = Building.Cast( MissionBuilding );
			for ( int j=0; j < 5; j++ ) 
			{
				if ( Store.IsDoorOpen(j) ) Store.CloseDoor(j);
				if ( !Store.IsDoorLocked(j) ) Store.LockDoor(j); 
			}	
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 1000, false, Store );		
		}			
	}
	
	void ~CityMallMission()
	{	
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{				
				if ( !m_MissionObjects.Get(i))	continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );			
			}
			m_MissionObjects.Clear();
		}
		
		
		//Delete mission AI's
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
	
	void SpawnSupplies()
	{		
		if ( m_MissionExtended )
		{
			//Spawn antibiotics
			for ( int i=0; i < MedSpawns.Count(); i++ )		
			{
				Object Med = GetGame().CreateObject("TetracyclineAntibiotics", MissionBuilding.ModelToWorld("-5.836 -0.216 1.005")); //safe position
				vector MedPos = MissionBuilding.ModelToWorld( MedSpawns.Get(i) );
				Med.SetPosition( MedPos );
				m_MissionObjects.Insert( Med );
			}
			
			//Spawn cans of food
			for ( int j=0; j < FoodSpawns.Count(); j++ )
			{
				string Can = FoodTypes.GetRandomElement();
				vector CanPos = MissionBuilding.ModelToWorld( FoodSpawns.Get(j) );
				Object CanOfFood = GetGame().CreateObject( Can , CanPos );
				CanOfFood.SetPosition( CanPos );
				m_MissionObjects.Insert( CanOfFood );
			}
		}
		else
		{
			//Spawn orange MountainBag 
			vector RewardPos = MissionBuilding.ModelToWorld( RewardsPosition );
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "MountainBag_Orange" , RewardPos ));
			m_MissionObjects.InsertAt( MissionObject, 0 );
		} 		
	}
	
	void SpawnRewards()
	{
		//new MissionObject after deleting orange bag
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "OH_military_box_big_model_two_events", m_MissionPosition ));
		

		ref array<string> randomItems = RandomItemsList.GetItems();
		int m_rewards = 3;



		//Get random loadout 			
		int selectedLoadout = Math.RandomIntInclusive(0,11);	//!Change randomization limit after adding new loadouts!
		
		//Spawn selected loadout items in mission object
		EntityAI weapon;
								
		if (selectedLoadout == 0)
		{
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
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 2)
		{
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
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
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
		
	}
	
	void SpawnObjects()
	{	
		Object FoundObject;
		
		if ( m_MissionExtended )
		{	
			//New MissionPosition is at cash desk
			m_MissionPosition = MissionBuilding.ModelToWorld( TargetPosition );
	 		
			//Clean up cash desk spawnpoints
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.5, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
			
			//Spawn supplies 1 second later			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnSupplies, 1000 );
			
			//Spawn barricades		
			for ( int j=0; j < Barricades.Count(); j++ )
			{
				Param3<string,vector,vector> BarricadeDef = Barricades.Get(j);
				string BarricadeType = BarricadeDef.param1;
				vector BarricadePos = MissionBuilding.ModelToWorld( BarricadeDef.param2 );
				vector BarricadeOri = BarricadeDef.param3;
				vector BarricadeDir = MissionBuilding.GetDirection();
				Object PlankBarricade;
				
				
				if ( BarricadeType == "Land_Boat_Small1" )
				PlankBarricade = GetGame().CreateObject( BarricadeType, BarricadePos, true );
				else
				{
					PlankBarricade = GetGame().CreateObject( BarricadeType, BarricadePos );
					if ( BarricadeType == "MetalPlate" || BarricadeType == "WoodenPlank" )
					{						
						ItemBase.Cast( PlankBarricade ).SetQuantity(1);
						ItemBase.Cast( PlankBarricade ).SetTakeable( false );
					}					 
				}
				PlankBarricade.SetPosition( BarricadePos );
				PlankBarricade.SetDirection( BarricadeDir );
				PlankBarricade.SetOrientation( PlankBarricade.GetOrientation() + BarricadeOri );

				m_MissionObjects.Insert( PlankBarricade );
			}
			
			//Spawn dead survivors hideout legacy	
			EntityAI Cooker = EntityAI.Cast( GetGame().CreateObject( "PortableGasStove", MissionBuilding.ModelToWorld("-5.96 -0.2156 0.84")));
			Cooker.GetInventory().CreateAttachment("SmallGasCanister");
			Cooker.GetInventory().CreateAttachment("Pot");
			m_MissionObjects.Insert( Cooker );
			
			m_MissionObjects.Insert( GetGame().CreateObject( "Paper", MissionBuilding.ModelToWorld("-9.74 -1.17 -7.49") ));
			m_MissionObjects.Insert( GetGame().CreateObject( "Paper", MissionBuilding.ModelToWorld("-8.18 -1.17 -8.09") ));
			m_MissionObjects.Insert( GetGame().CreateObject( "ShitGround", MissionBuilding.ModelToWorld("-9.54 -1.17 -7.69") ));
			m_MissionObjects.Insert( GetGame().CreateObject( "ShitGround", MissionBuilding.ModelToWorld("-9.34 -1.17 -7.89") ));
			
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...primary mission deployed!");
		}
		else
		{
			//New MissionPosition is bed in quiet room 
			m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
	 		
			//Clean up bed spawnpoint
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int k=0; k < m_ObjectList.Count(); k++)
				{
					FoundObject = m_ObjectList.Get(k);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
						
			//Spawn mission target orange MountainBag 1 second later			
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnSupplies, 1000 );	
						
			Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...secondary mission deployed!");
		}
	}
	
	void SpawnAIs()
	{	
		string RandomInfected;
		vector InfectedPos;
		int DeadInfectedCount = 3;
		DayZInfected Zed;
				
		if ( !MissionBuilding ) Print("[SMM] Extended Mission : Missionbuilding couldn't be found in "+ m_MissionDescription[3] +"." );		
		else
		{
			if ( m_MissionExtended )
			{
				//Spawn some infected at city store
				for ( int j = 0 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( PriInfectSpawns.Get(j) );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					if ( j < DeadInfectedCount ) Zed.SetHealth("","",0);
					m_MissionAIs.Insert( Zed );
				}
			}
			else
			{
				//Spawn some infected at Police Station
				for ( int k = 0 ; k < SecInfectSpawns.Count() ; k++ )
				{
		    	   	RandomInfected = InfectedTypes.GetRandomElement();
					InfectedPos = MissionBuilding.ModelToWorld( SecInfectSpawns.Get(k) );
					Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}		
			}
		}
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			if ( m_MissionObjects.Get(i))
			{
				//Exception: Barricades will remain
				if ( m_MissionObjects.Get(i).GetType() == "MetalPlate" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "WoodenPlank" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Roadblock_Table" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Roadblock_WoodenCrate" ) continue;
				if ( m_MissionObjects.Get(i).GetType() == "Land_Boat_Small1" ) continue;
			
				//Delete Object
				GetGame().ObjectDelete( m_MissionObjects.Get(i) );
			}		
		}
	}
	
	void ExtendMission()
	{	//When player enters mission target zone at primary mission

		//Set messages for secondary mission
		// m_MissionMessage1 = "Allright you have found the supplies, try to get out there safely. Ms. "+ SurvivorName +" never told me her whereabouts because she wants to be absolutely secure from bandits and scavengers.";
		// m_MissionMessage2 = "I think the best will be if you could deposit the supplies in the quiet room of the small\n  "+ m_MissionDescription[3] +"   police station and put all in the orange backpack i left there. I will check it in one hour and try to contact her on radio.";
		// m_MissionMessage3 = "I have some things for you at the small police station. Be careful, there might be bandits around "+ m_MissionDescription[3] +". They could intercepted our little radio talk here. Good luck!";
		
		m_MissionMessage1 = "Добре, ти знайшов усе необхідне. Постарайся вибратись звідти безпечно. Пані " + SurvivorName + " не повідомляє своє місцезнаходження, щоби уникнути небезпеки.";
		m_MissionMessage2 = "Залиши речі в поліцейському відділку\n  " + m_MissionDescription[3] + "  у помаранчевому рюкзаку. Я перевірю його і передам усе їй.";
		m_MissionMessage3 = "Будь пильний, поблизу можуть бути бандити. Вони перехоплюють радіозв’язок. Удачі!";

		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout for secondary mission
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for secondary mission		
		m_MissionZoneOuterRadius = 80.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get secondary mission position
		if ( EventsWorldData.GetBuildingsAtLoc("Land_Village_PoliceStation", m_MissionDescription[3], ExtendedPosList ))
		m_MissionPosition = ExtendedPosList.GetRandomElement();
		else Print("[SMM] Can't get secondary MissionPosition in "+ m_MissionDescription[3] +" from EventsWorldData!");
		
		//Search for mission building at old mission position and spawn 2. wave of infected
		GetGame().GetObjectsAtPosition( m_MissionPositions.Get( m_selectedMission ) , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_City_Store")
			{	
				Object Store = FoundObject;			 
				//Spawn infected at store outdoor
				for ( int j = 5 ; j < PriInfectSpawns.Count() ; j++ )
				{
		    	   	string RandomInfected = InfectedTypes.GetRandomElement();
					vector InfectedPos = Store.ModelToWorld( PriInfectSpawns.Get(j) );
					DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}
				
				break;
			}	
		}			
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		
		//Spawn second wave of infected at secondary mission
		SpawnAIs();		
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "MountainBag_Orange" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] ) ) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}
		
		//Check if container has desired amount of mushrooms collected at primary mission position
		if ( MissionObject && MissionObject.ClassName() == "MountainBag_Orange" && !m_MissionExtended )
		{
			int CargoCount = MissionObject.GetInventory().CountInventory();
			int LastCount = 0;
			int FoundMedObjects = 0;
			int FoundFoodObjects = 0;
			
			if ( CargoCount != LastCount )
			{
				if ( CargoCount >= ReqFoodAmount + ReqMedAmount && FoundMedObjects <= ReqMedAmount && FoundFoodObjects <= ReqFoodAmount )
				{	
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
					
					for ( int i = 0; i < CargoCount; i++ )
					{
						EntityAI CargoItem = CargoItems1.GetItem(i); 
						Object CargoObject = CargoItem;

						if ( m_MissionObjects.Find( CargoObject ) > -1 ) 
						{
							if ( CargoObject.GetType() == "TetracyclineAntibiotics")	FoundMedObjects++; 
							if ( FoodTypes.Find( CargoObject.GetType() ) > -1 )			FoundFoodObjects++;
						}
						else continue;					
						
						//When requested amount of supplies is present, despawn MissionObject & spawn rewards
						if ( FoundFoodObjects >= ReqFoodAmount && FoundMedObjects >= ReqMedAmount )
						{
							Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ (ReqFoodAmount + ReqMedAmount) +" MissionObjects in the container.");
							//delete container first
							GetGame().ObjectDelete( MissionObject );
							//call rewards spawn one second later 
							GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnRewards, 1000 );
							m_RewardsSpawned = true;
							m_MsgNum = -1;
							m_MsgChkTime = m_MissionTime + MsgDlyFinish;
							break;
						} 
					}
					LastCount = CargoCount;
				}
			} 
		}				
	}
		
	void UpdateBots( float dt )
	{
		//No bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at secondary mission position
		if ( !m_MissionExtended )
		{			
			GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int i=0; i < m_ObjectList.Count(); i++ )
			{ 
				Object FoundObject = m_ObjectList.Get(i);
				if ( FoundObject.GetType() == "Land_Village_PoliceStation")
				{			 
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is "+ m_MissionDescription[3] +" Police Station @ "+ m_MissionPosition );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( RewardsPosition );
					break;
				}	
			}
		}
		
		if ( MissionBuilding )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : MissionBuilding can't be found!");
			if ( MissionSettings.DebugMode ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}

