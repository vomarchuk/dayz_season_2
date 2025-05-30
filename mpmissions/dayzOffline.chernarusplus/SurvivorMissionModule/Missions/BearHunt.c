class BearHuntMission extends SurvivorMissions
{
	//Mission related entities
	ItemBase MissionObject;
	Object MissionBuilding;

	//Mission parameters
	int ReqMeatAmount = Math.RandomInt(2, 6);				//pieces, requested mushroom amount
	int ExtendedTimout = 1800;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	
	//Mission variables 
	string SurvivorName;		
	
	bool IsExtended() return true;
	
	void BearHuntMission()
	{	
		//Select primary mission
		m_MissionExtended = true;
				
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, mission max duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 80.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Мисливець";
	
		//Mission person names
		TStringArray SurvivorNames = {"Юрій", "Михайло", "Борис", "валерій", "Анатолій", "Степан", "Олексій", "Дмитро", "Сергій", "Микола" };
		SurvivorName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		// m_MissionMessage1 = "A survivor recently reported to me that a bear attacked my friend "+ SurvivorName +" and killed 2 other survivor's. They went to the wrong location trying to hunt some deer in the forest of "+ m_MissionLocation +".";
		// m_MissionMessage2 = "I still can't believe it. "+ SurvivorName +" was one of the best hunters araound here. Once a week he brought fresh meat to the hidden camp to feed the survivor's. He was never selfless and tried to do everything to help out in the camp.";
		// m_MissionMessage3 = "The bear was last reported at the forest near\n  "+ m_MissionLocationDir +" of "+ m_MissionLocation +"  \nI want you to kill this animal and take his pelt. It's not for revenge, we just need the pelt to make winter clothing for the kids. Be careful!";
		
		m_MissionMessage1 = "Кажуть, на " + SurvivorName + " напав ведмідь. Разом із ним загинули ще двоє. Вони переплутали маршрут, коли йшли на полювання поблизу " + m_MissionLocation + ".";
		m_MissionMessage2 = SurvivorName + " був одним із найкращих мисливців. Раз на тиждень він приносив м’ясо до табору. Його відданість справі була прикладом для всіх.";
		m_MissionMessage3 = "Останній раз ведмедя бачили " + m_MissionLocationDir + " від " + m_MissionLocation + " \n Знищ його і принеси шкіру — нам потрібні матеріали для зимового одягу та їжа. Бережи себе!";


		//Spawnpoint for MissionObject for secondary mission
		Spawnpoints.Insert("-18.40 2.19 18.57");
				
		//Infected spawnpoints for secondary mission
		InfectedSpawns.Insert("-7.46 -4.94 -12.99");
		InfectedSpawns.Insert("-15.65 -4.93 -22.08");
		InfectedSpawns.Insert("-22.5 -4.93 1.95");
		InfectedSpawns.Insert("-21.93 -4.93 13.0");
		InfectedSpawns.Insert("-17.95 -4.93 21.84");
		InfectedSpawns.Insert("-6.77 -4.89 21.28");
		InfectedSpawns.Insert("-21.14 -1.83 -5.83");
		InfectedSpawns.Insert("-10.5 1.27 -22.22");
		//...outside MissionBuilding 
		InfectedSpawns.Insert("0.23 -5.52 3.55");
		InfectedSpawns.Insert("19.78 -5.52 -5.66");
		
		//Infected types for secondary mission position
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
	
	void ~BearHuntMission()
	{	
		//Despawn all remaining objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
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
	
	void SpawnContainer()
	{
		MissionObject =  ItemBase.Cast( GetGame().CreateObject( "OH_military_box_big_model_two_events", m_MissionPosition )); //HuntingBag
		m_MissionObjects.InsertAt( MissionObject, 0); 		
	}
	
	void SpawnRewards()
	{
		//new MissionObject after deleting protector case
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "OH_military_box_big_model_two_events", m_MissionPosition ));
		
		ref array<string> randomItems = RandomItemsList.GetItems();
		int m_rewards = 4;

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
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

		}
		if (selectedLoadout == 4)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("CZ75");
				weapon.GetInventory().CreateAttachment("PistolSuppressor");
				weapon.GetInventory().CreateAttachment("FNP45_MRDSOptic");
			MissionObject.GetInventory().CreateInInventory("Mag_CZ75_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");

				
		}
		if (selectedLoadout == 5)
		{					
			MissionObject.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
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
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}
		if (selectedLoadout == 7)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
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
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			
		}
		if (selectedLoadout == 9)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_545x39_20Rnd");
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
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_762x39_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
	
		}
		if (selectedLoadout == 11)
		{			
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_45ACP_25rnd");
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
		
		ref array<string> randomMedItems = {
			"TerjeAmpouleZivirol", "TerjeAmpouleFlemoclav", "TerjeSyringeNew", "TerjeInjectorNeirox", 
			"TerjeSurgicalKit", "TerjePillsAmoxiclav", "TerjePillsPiperacylin"
		};


		int randomMedIndex = Math.RandomInt(0, randomMedItems.Count()); 
		string randomMedItem = randomMedItems.Get(randomMedIndex);       
		if (MissionObject.GetInventory().CreateInInventory(randomMedItem))
		{
			Print("[SMM] Добавлен предмет: " + randomMedItem);
		}
		else
		{
			Print("[SMM] Ошибка добавления предмета: " + randomMedItem);
		}

		MissionObject.GetInventory().CreateInInventory("WeaponCleaningKit");	
	}
	
	void SpawnObjects()
	{			
		if ( m_MissionExtended )
		{	
			//Spawn no objects at primary mission
		}
		else
		{				
			if ( MissionBuilding )
			{
				//Cleanup position before spawning protector case
				GetGame().GetObjectsAtPosition( m_MissionPosition, 0.5, m_ObjectList, m_ObjectCargoList );
				for ( int k = 0; k < m_ObjectList.Count(); k++ )
				{
					Object FoundObject = m_ObjectList.Get(k);
					if ( FoundObject.IsItemBase() )
					GetGame().ObjectDelete( FoundObject );
				}
				
				//Spawn container
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnContainer, 1000 );
								
				Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...mission extended!");
			}
			else Print("[SMM] Extended MissionBuilding couldn't be found in "+ m_MissionDescription[3] +" ... Mission rejected!");
		}
	}
	
	void SpawnAIs()
	{	
		if ( m_MissionExtended )
		{
			//Spawn Bear at primary mission
			m_MissionAIs.Insert( GetGame().CreateObject("Animal_UrsusArctos", m_MissionPosition, false, true)); 
			
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
		}
		else
		{
			if ( MissionBuilding )
			{			
				//Spawn some infected at school 
				for ( int j = 0 ; j < InfectedSpawns.Count() ; j++ )
				{
		    	   	string RandomInfected = InfectedTypes.GetRandomElement();
					vector InfectedPos = MissionBuilding.ModelToWorld( InfectedSpawns.Get(j) );
					DayZInfected Zed = DayZInfected.Cast( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ));
					m_MissionAIs.Insert( Zed );
				}			
			}
		}
	}
	
	void ObjDespawn() 
	{	
		//Despawn nothing
	}
	
	void ExtendMission()
	{
		//Set new mission messages
		// m_MissionMessage1 = "Allright survivor, you have found the bear location. Try to safely engage and kill him by aiming at his head or heart. A bear is a strong animal, so it will take some shots to get him down.";
		// m_MissionMessage2 = "Take out your knife and eviscerate him. Bring the pelt and the meat to the\n  "+ m_MissionDescription[3] +" School laboratory class room  \n(left wing, top floor) because I want to examine the bear meat. I left a hunting bag on the labor desk.";
		// m_MissionMessage3 = "Put atleast "+ ReqMeatAmount +" bear steaks and the pelt in there. Be carefull, there might be bandits around which could intercepted our little radio talk here. Good luck!";
		

		m_MissionMessage1 = "Добре, ти знайшов місцезнаходження ведмедя. Спробуй убити його, поціливши в голову або серце. Ведмідь — сильна тварина, тому знадобиться кілька пострілів, щоб його вбити.";
		m_MissionMessage2 = "Вийми ніж і розпотроши його. Принеси шкіру та м’ясо до\n  " + m_MissionDescription[3] + " класної кімнати шкільної лабораторії \n (ліве крило, верхній поверх), я хочу оглянути ведмеже м’ясо — я залишив скриню на робочому столі.";
		m_MissionMessage3 = "Поклади туди щонайменше " + ReqMeatAmount + " ведмежих стейків та шкіру. Будь обережний — навколо можуть бути бандити, які перехопили нашу невеличку радіорозмову. Удачі!";

		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for extended mission
		m_MissionZoneOuterRadius = 120.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get building position from building type and location
		if ( EventsWorldData.GetBuildingsAtLoc("Land_City_School", m_MissionDescription[3], ExtendedPosList ))
		{
			//Get MissionPosition for MissionBuilding from secondary mission
			m_MissionPosition = ExtendedPosList.GetRandomElement();						
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int m=0; m < m_ObjectList.Count(); m++ )
			{ 
				Object FoundObject = m_ObjectList.Get(m);
				if ( FoundObject.GetType() == "Land_City_School" )
				{	
					MissionBuilding = FoundObject;			 
										
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.Get(0) );
					break;
				}	
			}
		}
		else Print("[SMM] Can't find MissionBuilding City School in "+ m_MissionDescription[3] +"!");
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone	
		//Spawn infected
		string RandomInfected;
		vector InfectedPos;
		
		for ( int k = 0 ; k < InfectedSpawns.Count() ; k++ )
		{
    	   	RandomInfected = InfectedTypes.GetRandomElement();
			InfectedPos = MissionBuilding.ModelToWorld( InfectedSpawns.Get(k) );
			m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );
		}
				
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Update Bear position 
		if ( m_MissionExtended )
		{
			Object Bear = Object.Cast( m_MissionAIs[0] );
			if ( Bear && Bear.ClassName() == "Animal_UrsusArctos" )
			m_MissionPosition = Bear.GetPosition();
		}
		
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "OH_military_box_big_model_two_events" ) // HuntingBag
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
		if ( MissionObject && MissionObject.ClassName() == "OH_military_box_big_model_two_events" && !m_MissionExtended ) // HuntingBag
		{
			int CargoCount = MissionObject.GetInventory().CountInventory();
			int LastCount = 0;
			int FoundMeatObjects = 0;
			bool FoundPeltObject = false;
			
			if ( CargoCount != LastCount )
			{
				if ( CargoCount >= ReqMeatAmount && FoundMeatObjects <= ReqMeatAmount )
				{	
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
					
					for ( int i = 0; i < CargoCount; i++ )
					{
						EntityAI CargoItem = CargoItems1.GetItem(i);
						if ( CargoItem && CargoItem.GetType() == "BearSteakMeat" ) FoundMeatObjects++;
						else if ( CargoItem && CargoItem.GetType() == "BearPelt" ) FoundPeltObject = true;
						else continue;					
						
						//When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
						if ( FoundMeatObjects >= ReqMeatAmount && FoundPeltObject )
						{
							Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ ReqMeatAmount +" MissionObjects in the container.");
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
		
	void UpdateBots(float dt)
	{
		//No bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at mission position
		if ( !m_MissionExtended && !MissionBuilding )
		{
			if ( EventsWorldData.GetBuildingsAtLoc("Land_City_School", m_MissionDescription[3], ExtendedPosList ))
			{		
				//Get MissionPosition for MissionBuilding from secondary mission
				m_MissionPosition = ExtendedPosList.GetRandomElement();						
				GetGame().GetObjectsAtPosition( m_MissionPosition, 1.0 , m_ObjectList , m_ObjectCargoList );
				for ( int m=0; m < m_ObjectList.Count(); m++ )
				{ 
					Object FoundObject = m_ObjectList.Get(m);
					if ( FoundObject.GetType() == "Land_City_School" )
					{	
						MissionBuilding = FoundObject;			 
						Print("[SMM] MissionBuilding extended is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[3] +" @ "+ MissionBuilding.GetPosition() );
											
						//new MissionPosition is rewards spawnpoint
						m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.Get(0) );
						break;
					}	
				}
			}
			else Print("[SMM] Can't find MissionBuilding City School in "+ m_MissionDescription[3] +"!");	
		}
		
					
		if ( (m_MissionPosition && m_MissionPosition != "0 0 0" && m_MissionExtended) || (MissionBuilding && !m_MissionExtended) )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] Mission position was rejected or MissionBuilding doesn't exist!");
			if ( MissionSettings.DebugMode && !MissionBuilding && !m_MissionExtended ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}

