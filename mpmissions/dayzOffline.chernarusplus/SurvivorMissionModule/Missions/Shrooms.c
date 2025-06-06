class ShroomsMission extends SurvivorMissions
{
	// Mission related entities
	ItemBase MissionObject;
	Object MissionBuilding;

	// Mission parameters
	int ReqShroomsCount = 10;  // pieces, requested mushroom amount
	int ExtendedTimout = 1800; // seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;	   // seconds, message delay time after player has finished mission

	// Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;

	// Mission variables
	string SurvivorName;
	string SurvivorExtName;

	bool IsExtended() return true;

	void ShroomsMission()
	{
		// Select primary mission
		m_MissionExtended = true;

		// Mission timeout
		m_MissionTimeout = 2700; // seconds, mission max duration time

		// Mission zones
		m_MissionZoneOuterRadius = 70.0; // meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 30.0; // meters (!Do not set outside of 1-5m), mission finishing distance to target object

		// Mission informant
		m_MissionInformant = "Степан Бандера";

		// Mission person names
		TStringArray SurvivorNames = {"Юрій", "Михайло", "Борис", "валерій", "Анатолій", "Іван", "Олексій", "Дмитро", "Сергій", "Микола"};
		SurvivorName = SurvivorNames.GetRandomElement();
		TStringArray SurvivorExtNames = {"Тимаренко", "Лозинська", "Бласенко", "Гаварук", "Слоскова", "Білозір", "Хом’як", "Трембович", "Янковська"};

		SurvivorExtName = SurvivorExtNames.GetRandomElement();

		// Set mission messages for primary mission
		//  m_MissionMessage1 = SurvivorName +", a survivor i met a few days ago told me that there are some places around here with numerous occurrencies of a special mushroom. It's classification name is 'Psilocybe semilanceata'.";
		//  m_MissionMessage2 = "At the moment i am experimenting with the containing psychoactive substance Psilocybin on infected wild animals. The animals show interesting behaviors after 30 minutes of the oral intake. I can't say much about it yet, but for my experiments I need more mushrooms.";
		//  m_MissionMessage3 = SurvivorName +" said that he found some of those anywhere\n** "+ m_MissionLocationDir +" of "+ m_MissionLocation +" **\nI need "+ ReqShroomsCount +" more pieces of it. The mushrooms are very small. I recommend using a mushroom encyclopedia for possible occurrencies!";

		m_MissionMessage1 = SurvivorName + ", виживший, якого я зустрів кілька днів тому, розповів мені, що тут є місця з численними випадками росту особливого гриба. Його класифікаційна назва - 'Psilocybe semilanceata'.";
		m_MissionMessage2 = "Зараз я експериментую з психоактивною речовиною псилоцибіном, яка міститься в ньому, на заражених диких тваринах. Тварини демонструють цікаву поведінку через 30 хвилин після прийому всередину. Я поки не можу багато сказати, але для моїх експериментів мені потрібно більше грибів.";
		m_MissionMessage3 = SurvivorName + " сказав, що він знайшов кілька з них десь\n** " + m_MissionLocationDir + " від " + m_MissionLocation + " **\nМені потрібно ще " + ReqShroomsCount + " штук. Ці гриби дуже маленькі. Рекомендую використовувати енциклопедію грибів для можливих місць зростання!";

		// Spawnpoints for MissionObject for secondary mission
		Spawnpoints.Insert("-20.2900 -6.6398 0.7559");
		Spawnpoints.Insert("-20.2568 -6.6398 5.2510");
		Spawnpoints.Insert("-15.2871 -6.6398 5.0928");
		Spawnpoints.Insert("-10.0518 -6.6401 8.1748");
		Spawnpoints.Insert("-8.4160 -6.6398 7.6533");
		Spawnpoints.Insert("-4.0557 -6.6398 7.9033");

		// Infected spawnpoints for secondary mission
		InfectedSpawns.Insert("-6.3779 -7.3111 1.6016");
		InfectedSpawns.Insert("-12.0635 -7.3111 -2.3115");
		InfectedSpawns.Insert("0.5469 -7.3111 -1.01953");
		InfectedSpawns.Insert("-2.1709 -7.3111 -0.9775");
		InfectedSpawns.Insert("-16.0303 -7.3111 -2.0146");
		InfectedSpawns.Insert("17.8955 -7.3067 4.6143");
		InfectedSpawns.Insert("17.6504 -3.5781 -0.2275");
		//...outside MissionBuilding
		InfectedSpawns.Insert("-17.0156 -7.6364 -9.7158");
		InfectedSpawns.Insert("-7.4268 -7.6066 -11.7314");
		InfectedSpawns.Insert("0.8662 -7.6027 -9.7480");
		InfectedSpawns.Insert("10.6084 -7.6134 -8.6611");
		InfectedSpawns.Insert("18.0771 -7.5431 -9.1602");

		// Infected types for secondary mission position
		// Male												//Female
		InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");
		InfectedTypes.Insert("ZmbF_JournalistNormal_White");
		InfectedTypes.Insert("ZmbM_priestPopSkinny");
		InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
		InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");
		InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Red");
		InfectedTypes.Insert("ZmbF_CitizenBSkinny");
		InfectedTypes.Insert("ZmbM_FishermanOld_Green");
		InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
		InfectedTypes.Insert("ZmbM_HunterOld_Autumn");
		InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");
		InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
		InfectedTypes.Insert("ZmbM_MotobikerFat_Black");
		InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");
		InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
		InfectedTypes.Insert("ZmbM_HandymanNormal_Green");
		InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
		InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");
		InfectedTypes.Insert("ZmbF_PatientOld");
		InfectedTypes.Insert("ZmbM_Jacket_black");
		InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
		InfectedTypes.Insert("ZmbM_Jacket_stripes");
		InfectedTypes.Insert("ZmbF_VillagerOld_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");
		InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
		InfectedTypes.Insert("ZmbM_PolicemanFat");
		InfectedTypes.Insert("ZmbF_VillagerOld_Green");
		InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");
		InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");
		InfectedTypes.Insert("ZmbF_NurseFat");
		InfectedTypes.Insert("ZmbM_VillagerOld_White");
		InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
		InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");
		InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");
		InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
		InfectedTypes.Insert("ZmbM_DoctorFat");
		InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
		InfectedTypes.Insert("ZmbM_PatientSkinny");
		InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
		InfectedTypes.Insert("ZmbM_ClerkFat_Brown");
		InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
		InfectedTypes.Insert("ZmbM_ClerkFat_White");
		InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
		InfectedTypes.Insert("ZmbM_Jacket_magenta");
		InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
		InfectedTypes.Insert("ZmbM_PolicemanSpecForce");
		InfectedTypes.Insert("ZmbF_DoctorSkinny");
	}

	void ~ShroomsMission()
	{
		// Despawn all remaining objects
		if (m_MissionObjects)
		{
			Print("[SMM] Despawning " + m_MissionObjects.Count() + " mission objects from old mission...");
			for (int i = 0; i < m_MissionObjects.Count(); i++)
			{
				if (!m_MissionObjects.Get(i))
					continue;
				else
					GetGame().ObjectDelete(m_MissionObjects.Get(i));
			}
			m_MissionObjects.Clear();
		}

		// Delete mission AI's
		if (m_MissionAIs)
		{
			if (m_MissionAIs.Count() > 0)
			{
				Print("[SMM] Despawning " + m_MissionAIs.Count() + " mission AI's from old mission...");
				for (int k = 0; k < m_MissionAIs.Count(); k++)
				{
					GetGame().ObjectDelete(m_MissionAIs.Get(k));
				}
				m_MissionAIs.Clear();
			}
			else
				Print("[SMM] No mission AI's to despawn.");
		}

		// Delete PlayersInZone list & reset container takeaway
		if (m_PlayersInZone)
			m_PlayersInZone.Clear();
		if (m_ContainerWasTaken)
			m_ContainerWasTaken = false;
	}

	void SpawnContainer()
	{
		MissionObject = ItemBase.Cast(GetGame().CreateObject("SmallProtectorCase", m_MissionPosition));
		m_MissionObjects.InsertAt(MissionObject, 0);
	}

	void SpawnRewards()
	{
		// new MissionObject after deleting protector case
		MissionObject = ItemBase.Cast(GetGame().CreateObject("MountainBag_Green", m_MissionPosition));

		// Get random loadout
		int selectedLoadout = Math.RandomIntInclusive(0, 9); //! change randomization limit after adding new loadouts!

		// Spawn selected loadout items in mission object
		EntityAI weapon;

		if (selectedLoadout == 0)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("M4A1_Green");
			weapon.GetInventory().CreateAttachment("M4_RISHndgrd_Green");
			weapon.GetInventory().CreateAttachment("M4_MPBttstck");
			weapon.GetInventory().CreateAttachment("ACOGOptic");
			weapon.GetInventory().CreateAttachment("M4_Suppressor");
			MissionObject.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			MissionObject.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			MissionObject.GetInventory().CreateInInventory("Ammo_556x45");
			MissionObject.GetInventory().CreateInInventory("Ammo_556x45");
			MissionObject.GetInventory().CreateInInventory("CanOpener");
			MissionObject.GetInventory().CreateInInventory("PeachesCan");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 1)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("IMP_SVD");
			weapon.GetInventory().CreateAttachment("PSO1Optic");
			MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			MissionObject.GetInventory().CreateInInventory("PSO1Optic");
			MissionObject.GetInventory().CreateInInventory("KazuarOptic");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("CanOpener");
			MissionObject.GetInventory().CreateInInventory("PeachesCan");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 2)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("AKM");
			weapon.GetInventory().CreateAttachment("AK_RailHndgrd_Green");
			weapon.GetInventory().CreateAttachment("AK_PlasticBttstck_Green");
			weapon.GetInventory().CreateAttachment("PSO1Optic");
			weapon.GetInventory().CreateAttachment("AK_Suppressor");
			MissionObject.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x39");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x39");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x39");
			MissionObject.GetInventory().CreateInInventory("CanOpener");
			MissionObject.GetInventory().CreateInInventory("PeachesCan");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 3)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("FAL");
			weapon.GetInventory().CreateAttachment("Fal_OeBttstck");
			MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_FAL_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AK_Suppressor");
			MissionObject.GetInventory().CreateInInventory("ACOGOptic");
			MissionObject.GetInventory().CreateInInventory("FNX45");
			MissionObject.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_45ACP");
			MissionObject.GetInventory().CreateInInventory("FNP45_MRDSOptic");
			MissionObject.GetInventory().CreateInInventory("PistolSuppressor");
			MissionObject.GetInventory().CreateInInventory("PsilocybeMushroom");
			MissionObject.GetInventory().CreateInInventory("AmmoBox");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 4)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("SKS");
			weapon.GetInventory().CreateAttachment("PUScopeOptic");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x39");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x39");
			weapon = MissionObject.GetInventory().CreateInInventory("FNX45");
			weapon.GetInventory().CreateAttachment("PistolSuppressor");
			EntityAI weaponlight = weapon.GetInventory().CreateAttachment("TLRLight");
			weaponlight.GetInventory().CreateAttachment("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_45ACP");
			MissionObject.GetInventory().CreateInInventory("AmmoBox");
		}
		if (selectedLoadout == 5)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("Winchester70");
			weapon.GetInventory().CreateAttachment("HuntingOptic");
			MissionObject.GetInventory().CreateInInventory("Ammo_308Win");
			MissionObject.GetInventory().CreateInInventory("Ammo_308Win");
			MissionObject.GetInventory().CreateInInventory("FNX45");
			MissionObject.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_45ACP");
			MissionObject.GetInventory().CreateInInventory("AmmoBox");
			MissionObject.GetInventory().CreateInInventory("PistolSuppressor");
			MissionObject.GetInventory().CreateInInventory("TLRLight");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 6)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("MP5K");
			weapon.GetInventory().CreateAttachment("MP5_RailHndgrd");
			weapon.GetInventory().CreateAttachment("MP5k_StockBttstck");
			weapon.GetInventory().CreateAttachment("M68Optic");
			weapon.GetInventory().CreateAttachment("PistolSuppressor");
			MissionObject.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("GP5GasMask");
			MissionObject.GetInventory().CreateInInventory("NBCGlovesGray");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			MissionObject.GetInventory().CreateInInventory("M18SmokeGrenade_Red");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 7)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("AK74");
			weapon.GetInventory().CreateAttachment("AK_RailHndgrd");
			weapon.GetInventory().CreateAttachment("AK74_WoodBttstck");
			weapon.GetInventory().CreateAttachment("KashtanOptic");
			weapon.GetInventory().CreateAttachment("'AK_Suppressor");
			MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Headtorch_Grey");
			MissionObject.GetInventory().CreateInInventory("NBCBootsGray");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("TacticalBaconCan");
			MissionObject.GetInventory().CreateInInventory("Tomato");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 8)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("AKS74U");
			weapon.GetInventory().CreateAttachment("AKS74U_Bttstck");
			MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");
			MissionObject.GetInventory().CreateInInventory("Matchbox");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("PortableGasStove");
			MissionObject.GetInventory().CreateInInventory("SmallGasCanister");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}
		if (selectedLoadout == 9)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("Glock19");
			weapon.GetInventory().CreateAttachment("PistolSuppressor");
			MissionObject.GetInventory().CreateInInventory("IMP_Mag_Glock_21Rnd");
			MissionObject.GetInventory().CreateInInventory("IMP_Mag_Glock_21Rnd");
			MissionObject.GetInventory().CreateInInventory("FishingRod");
			MissionObject.GetInventory().CreateInInventory("Carp");
			MissionObject.GetInventory().CreateInInventory("Hook");
			MissionObject.GetInventory().CreateInInventory("Worm");
			MissionObject.GetInventory().CreateInInventory("CombatKnife");
			MissionObject.GetInventory().CreateInInventory("FieldShovel");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("MackerelFilletMeat");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
		}

		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was " + selectedLoadout + ".");
	}

	void SpawnObjects()
	{
		if (m_MissionExtended)
		{
			// Spawn mushroom occurence
			float OccurenceDist = 30 * 0.707;
			int MushroomsCount = Math.RandomIntInclusive(50, 150);
			vector SpawnPos;
			bool ItemsAtGround = false;

			MissionObject = ItemBase.Cast(GetGame().CreateObject("PsilocybeMushroom", m_MissionPosition));
			if (MissionObject)
				Print("[SMM] Mushrooms occurence spawned around @ " + MissionObject.GetPosition());

			m_MissionObjects.Insert(MissionObject);
			for (int j = 1; j < MushroomsCount; j++)
			{
				// calc new spawn position
				float x = Math.RandomFloatInclusive(0.5, OccurenceDist);
				float y = Math.RandomFloatInclusive(0.5, OccurenceDist);
				int Dice = Math.RandomIntInclusive(0, 9);
				if (Dice > 4)
					x *= -1.0;
				Dice = Math.RandomIntInclusive(0, 9);
				if (Dice < 5)
					y *= -1.0;
				vector NewPosVector = {x, 0, y};
				SpawnPos = m_MissionPosition + NewPosVector;

				// check for items at ground
				GetGame().GetObjectsAtPosition(SpawnPos, 1.0, m_ObjectList, m_ObjectCargoList);
				for (int i = 0; i < m_ObjectList.Count(); i++)
				{
					Object FoundObject = m_ObjectList.Get(i);
					if (FoundObject.IsItemBase() || FoundObject.IsTree() || FoundObject.IsRock() || FoundObject.IsBush())
					{
						ItemsAtGround = true;
						break;
					}
				}
				if (ItemsAtGround)
				{
					ItemsAtGround = false;
					j--;
					continue;
				}

				// spawn mushroom
				m_MissionObjects.Insert(GetGame().CreateObject("PsilocybeMushroom", SpawnPos));
			}

			Print("[SMM] Survivor Mission " + m_selectedMission + " :: " + m_MissionName + " ...mission deployed!");
		}
		else
		{
			if (MissionBuilding)
			{
				// Cleanup position before spawning protector case
				GetGame().GetObjectsAtPosition(m_MissionPosition, 0.5, m_ObjectList, m_ObjectCargoList);
				for (int k = 0; k < m_ObjectList.Count(); k++)
				{
					FoundObject = m_ObjectList.Get(k);
					if (FoundObject.IsItemBase())
						GetGame().ObjectDelete(FoundObject);
				}

				// Spawn container
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnContainer, 1000);

				Print("[SMM] Survivor Mission Extension " + m_selectedMission + " :: " + m_MissionName + " ...mission extended!");
			}
			else
				Print("[SMM] Extended MissionBuilding couldn't be found in " + m_MissionDescription[3] + " ... Mission rejected!");
		}
	}

	void SpawnAIs()
	{
		if (m_MissionExtended)
		{
			// Spawn no AIs at primary mission
		}
		else
		{
			// Spawn infected
			string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos;

			for (int k = 0; k < InfectedSpawns.Count(); k++)
			{
				RandomInfected = InfectedTypes.GetRandomElement();
				InfectedPos = MissionBuilding.ModelToWorld(InfectedSpawns.Get(k));
				m_MissionAIs.Insert(GetGame().CreateObject(RandomInfected, InfectedPos, false, true));
			}
		}
	}

	void ObjDespawn()
	{
		// Despawn all mission objects at mission timeout except those retains until next mission
		for (int i = 0; i < m_MissionObjects.Count(); i++)
		{
			// Exception: Psilo's will remain
			if (m_MissionObjects.Get(i) && m_MissionObjects.Get(i).GetType() == "PsilocybeMushroom")
				continue;

			// Delete Object
			GetGame().ObjectDelete(m_MissionObjects.Get(i));
			m_MissionObjects.Remove(i);
		}
	}

	void ExtendMission()
	{
		// Set new mission messages
		m_MissionMessage1 = "Allright survivor, if you have found " + ReqShroomsCount + " of these mushrooms bring them to the following place. Hold on a second...";
		m_MissionMessage2 = "Bring them to the ** " + m_MissionDescription[3] + " Hospital Office **\n" + SurvivorExtName + " said she could extract the active substance for me. She has a small protector case on her desk in her former office.";
		m_MissionMessage3 = "Put all you have found in there. Be carefull, there might be bandits around which could intercepted our little radio talk here. Good luck!";

		// init Messenger for new messages
		m_MsgNum = 1; // skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;

		// increase mission MissionTimeout
		m_MissionTimeout = m_MissionTime + ExtendedTimout;

		// deployment settings & init for extended mission
		m_MissionZoneOuterRadius = 90.0;
		m_MissionZoneInnerRadius = 2.0;

		// Get building position from building type and location
		if (EventsWorldData.GetBuildingsAtLoc("Land_City_Hospital", m_MissionDescription[3], ExtendedPosList))
		{
			// Get MissionPosition for MissionBuilding from secondary mission
			m_MissionPosition = ExtendedPosList.GetRandomElement();
		}
		else
			Print("[SMM] Can't find MissionBuilding City Hospital in " + m_MissionDescription[3] + "!");
	}

	void MissionFinal()
	{ // When player enters last mission target zone
	  // do nothing
	}

	void PlayerChecks(PlayerBase player)
	{
		// Check if container gets taken from player
		if (MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended)
		{
			if (m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "SmallProtectorCase")
			{
				if (player.GetInventory().HasEntityInInventory(EntityAI.Cast(m_MissionObjects[0])) && !m_ContainerWasTaken)
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete(m_MissionObjects[0]);
				}
			}
		}

		// Check if container has desired amount of mushrooms collected at primary mission position
		if (MissionObject && MissionObject.ClassName() == "SmallProtectorCase" && !m_MissionExtended)
		{
			int CargoCount = MissionObject.GetInventory().CountInventory();
			int LastCount = 0;
			int FoundObjects = 0;

			if (CargoCount != LastCount)
			{
				if (CargoCount >= ReqShroomsCount && FoundObjects <= ReqShroomsCount)
				{
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();

					for (int i = 0; i < CargoCount; i++)
					{
						EntityAI CargoItem = CargoItems1.GetItem(i);
						if (m_MissionObjects.Find(CargoItem) > -1)
							FoundObjects++;
						else
							continue;

						// When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
						if (FoundObjects >= ReqShroomsCount)
						{
							Print("[SMM] Player with SteamID64: " + player.GetIdentity().GetPlainId() + " has successfully stored the requested amount of " + ReqShroomsCount + " MissionObjects in the container.");
							// delete container first
							GetGame().ObjectDelete(MissionObject);
							// call rewards spawn one second later
							GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SpawnRewards, 1000);
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
		// No bots involved in this mission
	}

	bool DeployMission()
	{ // When first player enters the mission zone (primary/secondary)
		// Get MissionBuilding at mission position
		if (!m_MissionExtended && !MissionBuilding)
		{
			GetGame().GetObjectsAtPosition(m_MissionPosition, 1.0, m_ObjectList, m_ObjectCargoList);
			for (int m = 0; m < m_ObjectList.Count(); m++)
			{
				Object FoundObject = m_ObjectList.Get(m);
				if (FoundObject.GetType() == "Land_City_Hospital")
				{
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is " + MissionBuilding.GetType() + " at " + m_MissionDescription[3] + " @ " + MissionBuilding.GetPosition());

					// new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld(Spawnpoints.GetRandomElement());
					break;
				}
			}
		}

		if ((m_MissionPosition && m_MissionPosition != "0 0 0" && m_MissionExtended) || (MissionBuilding && !m_MissionExtended))
		{
			// Call spawners
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnObjects);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.SpawnAIs);
			return true;
		}
		else
		{
			Print("[SMM] Mission position was rejected or MissionBuilding doesn't exist!");
			if (MissionSettings.DebugMode && !MissionBuilding && !m_MissionExtended)
				Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}
