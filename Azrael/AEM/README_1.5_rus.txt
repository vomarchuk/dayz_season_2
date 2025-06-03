Azrael Equipment Mod (AEM)

Версия 1.5

Discord: alazrael

--RUS

######################## УСТАНОВКА ########################


------Файлы:
--Клиентская часть:
AP_equipment_core.pbo  -  не вскрывать/не изменять/не делать прочих нехороших действий
AP_equipment.pbo  -  не вскрывать/не изменять/не делать прочих нехороших действий
AP_equipment_2.pbo  -  не вскрывать/не изменять/не делать прочих нехороших действий
AP_equipment_proxy.pbo  -  здесь находятся прокси персонажа, разрешено редактировать*, адаптировать под себя в случае конфликтов с другими модами
AP_equipment_PUBLIC.pbo  -  разрешено редактировать*, содержит основные текстуры и конфиги
AP_equipment_PATCHES.pbo  -  разрешено редактировать*, содержит текстуры и конфиги нашивок

--Серверная часть:
AP_equipment_server.pbo  -  запрещено вскрывать, менять, распространять, должно быть только в серверной части

--Дополнительные файлы:
AP_equipment_TEXTURES.rar  -  основные текстуры для создания ретекстуров. НИКУДА УСТАНАВЛИВАТЬ НЕ НУЖНО, ЭТО ВСПОМОГАТЕЛЬНЫЕ ФАЙЛЫ.

* - настоятельно рекоммендую не менять исходные файлы, а лишь использовать их для получения информации, классов и тд. Лучше делать все изменения модом сверху.


 
######################## НАСТРОЙКИ ########################
Настройка проверки инвентаря и слотов вещей в AP_equipment_PUBLIC.pbo
AP_equipment_PUBLIC\scripts\4_world\SuperSetting.c



json-конфиг, дефолтные значения:

{
    "ConfigVersion": "1",
    "TITLE": "[Azrael Equipment Mod]",
    "AUTHOR": "Al-Azrael",
    "DISCORD": "Discord: https://discord.gg/nTdfMS6bJF",
    "text1": "====== Damage Settings",
    "c_EnableNewArmorSystem": 1,   //включить новую систему расчета урона при использовании визоров, мандибул и тд..
    "c_DamageEquipFire": 4.0,   //модификатор повреждения для разгрузок, шлемов, визоров и тд от огнестрела
    "c_DamageEquipExplo": 8.0,   //от осколков
    "c_DamageEquipOther": 1.0,   //прочие типы урона
    "c_DamageVestModif": 1.0,   //дополнительный урон по бронежилету (0.0 - отключить, ванилла)
    "c_HealthDamageModifier": 1.0,   //модификатор урона при срабатывании визоров, доп. брони (чем больше - тем больше урон)
    "c_ShockDamageModifier": 1.0,   //модификатор шока
    "c_BloodDamageModifier": 1.0,   //модификатор урона по крови
    "text2": "====== Other Settings", 
    "c_BlockingSprint": 1,   //блокируют ли некоторые элементы снаряжения спринт (0 - выкл, 1 - вкл)
    "c_DumpingHelmet": 1,   //приглушение звука некоторыми шлемами (0 - выкл, 1 - вкл)
    "c_KillStamina": 1,    //доп. трата стамины при прыжке в тяжелой броне (редут) (0 - выкл, 1 - вкл)
    "c_MergeMagPouch": 1,    //возможность объединять и разъединять подсумки для магазинов (0 - выкл, 1 - вкл)
    "text3": "====== Headset Settings",
    "c_AccoModif": 0.3,   // НЕ ИСПОЛЬЗУЕТСЯ // множитель приглушения окружающего звука в активных наушниках
	"text4": "====== Camelbag Settings",
	"c_MinWater": 1000,  // минимальный порог уровня гидратации персоанажа при котором автоматически сработает гидратор
	"c_AddWater": 200,   // сколько воды добавляет гидратор за 1 тик
    "text5": "====== Compatibility Settings",
    "IncompatibilityWithVisor": [   //несовместимые с визорами маски, очки
        "GasMask",
        "GP5GasMask",
        "AirborneMask"
    ],
    "IncompatibilityWithHeadset": [   //несовместимые с активными наушниками головные уборы, маски, очки
        "ZSh3PilotHelmet",
        "Ushanka_ColorBase",
        "PumpkinHelmet",
        "MotoHelmet_ColorBase",
        "DarkMotoHelmet_ColorBase",
        "TankerHelmet",
        "GorkaHelmet",
        "FirefightersHelmet_ColorBase",
        "WeldingMask",
        "GreatHelm",
        "DirtBikeHelmet_ColorBase",
        "NBCHoodBase",
        "AP_helm_maska_Base",
        "AP_helm_altyn_Base",
        "AP_helm_vulkan_Base",
        "AP_helm_crew_Base"
    ],
    "IncompatibilityWithCloak": [  //несовместимые с гили накидкой (развернутый капюшон) головные уборы, маски, очки
        "AP_camo_cloak_Base",
        "ZSh3PilotHelmet",
        "PumpkinHelmet",
        "MotoHelmet_ColorBase",
        "DarkMotoHelmet_ColorBase",
        "GorkaHelmet",
        "FirefightersHelmet_ColorBase",
        "WeldingMask",
        "GreatHelm",
        "DirtBikeHelmet_ColorBase",
        "AP_helm_maska_Base",
        "AP_helm_altyn_Base",
        "AP_helm_vulkan_Base",
        "AP_helm_crew_Base"
    ],
    "CompatibilityWithBackpanel": [  //совместимые с бэкпанелью рюкзаки и сумки
        "AP_bag_duffel_Base",
        "GhillieBushrag_ColorBase",
        "GhillieTop_ColorBase",
        "GhillieSuit_ColorBase"
    ],
    "CompatibilityWithUnloading": [  //совместимые с разгрузочными системами бонежилеты (должен быть без аттачментов и пустой)
        "AP_vest_6b13_Base",
        "AP_vest_6b43_Base",
        "AP_vest_6b43_full_Base",
        "AP_vest_kirasa_Base",
        "AP_vest_kgb_Base"
    ],
    "c_CheckAttachmentsAndCargoOnVest": 1,   //проверка пустого инвентаря и отсутствия аттачментов у бронежилетов из списка CompatibilityWithUnloading
    "text6": "====== Armor Repair Settings",
    "c_DisableOldSystem": 0,   //выключить починку бронежилетов из списка ArmorRepairList ванильным способом
    "c_EnableNewSystem": 1,		//включить возможность починки новым ремнабором для бронежилетов из ArmorRepairList
    "c_EnableRuinRepair": 1,		//включить возможность починки новым ремнабором уничтоженных бронежилетов из ArmorRepairList
    "c_EnableWornRepair": 1,		//включить возможность починки новым ремнабором бронежилетов из ArmorRepairList до стостояния Нетронуто
    "c_KitBaseQuantityUse": 10,    //базовое значение отнимаемое от ремнабора при починке (так же влияет степень повреждения бронежилета и небольшой рандом)
    "ArmorRepairList": [  //список бронежилетов (можно использовать базовый класс) для изменения системы ремонта
        "AP_vest_platecarrier_Base",
        "AP_vest_runner_Base",
        "AP_vest_wardrum_Base",
        "AP_vest_wardrum_full_Base",
        "AP_vest_6b13_Base",
        "AP_vest_6b43_Base",
        "AP_vest_6b43_full_Base",
        "AP_vest_kirasa_Base",
        "AP_vest_redut_Base",
        "AP_vest_dcs_Base",
        "AP_vest_dcs_2_Base",
        "AP_vest_dcs_3_Base",
        "AP_vest_kgb_Base"
    ]
}