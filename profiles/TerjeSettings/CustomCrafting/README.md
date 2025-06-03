# General
You can create your own craft recipes on the server using this system.
Each individual craft recipe must be in a separate file in this folder. The file names do not matter, but must have the `.json` extension.

## Crafting recipes format

> **Name**
> The name of the recipe that will be displayed in the game. It is allowed to use localization tags defined in your `stringtable.csv`.

> **Enabled**
> Determines whether this recipe is enabled on the server. (0 - disabled, 1 - enabled)

> **IsInstaRecipe**
> Determines whether this recipe should be instant (0 - no, 1 - yes)

> **AnimationLength**
> Determines the time in seconds (floating number) required for the player to make this recipe (when `IsInstaRecipe` is off).

> **FirstIngredient** and **SecondIngredient**
> Two ingredients that must be combined in the game to produce a craft.
> 
>> **Items**
>> List of class names of items that can be used as an ingredient. It is allowed to use base classes when needed.
>
>> **DeleteRequired**
>> Determines whether the ingredient will be deleted after the end of the craft (0 - no, 1 - yes)
>
>> **MinQuantity**
>> The minimum amount of the quantity needed to start crafting. Floating number equal or greater then 0. Use -1 to disable the check.
>
>> **MaxQuantity**
>> The maximum possbile amount of the quantity to start crafting. Floating number equal or greater then 0. Use -1 to disable the check.
>
>> **MinDamage**
>> The minimum damage of the ingredient needed to start crafting. Floating number equal or greater then 0. Use -1 to disable the check.
>> *Important: this is not a health of the ingredient, but its state, where 0 is pristine, 1 is worn, 2 is damaged, 3 is badly damaged, 4 is ruined.*
>
>> **MaxDamage**
>> The maximum possbile damage of the ingredient to start crafting. Floating number equal or greater then 0. Use -1 to disable the check.
>> *Important: this is not a health of the ingredient, but its state, where 0 is pristine, 1 is worn, 2 is damaged, 3 is badly damaged, 4 is ruined.*
>
>> **AddHealth**
>> Determines how much health will be added to the ingredient after the crafting is complete. Can be used to repair items if `DeleteRequired` is turned off. Floating number equal or greater then 0.
>
>> **SetHealth**
>> Determines how much health will be set to the ingredient after the crafting is complete. Can be used to repair items if `DeleteRequired` is turned off. Floating number equal or greater then 0. Use -1 to disable this behaviour.
>
>> **AddQuantity**
>> Determines how many units of quantity will be added to the ingredient after crafting is completed. Can be used to repair items if `DeleteRequired` is turned off. Floating number equal or greater then 0.

> **CraftingResults**
> List with crafting results (can be empty if necessary)
>
>> **Item**
>> Class name of resulted item to be spawned.
>
>> **SetFullQuantity**
>> Use 1 to set full quantity or 0 to do nothing.
>
>> **SetQuantity**
>> Sets the specific quantity for the resulted item. Floating number equal or greater then 0. Use -1 to disable this behaviour.
>
>> **SetHealth**
>> Sets the specific number of health for the resulted item. Floating number equal or greater then 0. Use -1 to disable this behaviour.
>
>> **InheritsHealth**
>> Sets the specific behaviour for resulted items health. Use -1 to do nothing. Use -2 to this result will inherit health from all ingredients averaged. Or use 0 (first ingredient) or 1 (second ingredient) to this result will inherit health from the specific ingredient. 
>
>> **InheritsColor**
>> Sets the specific behaviour for resulted items color. Use -1 to do nothing. Or use 0 (first ingredient) or 1 (second ingredient) to composite result classname for this result item and config value 'color' of ingredient.
>
>> **ToInventory**
>> Sets the specific behaviour to determine spawning position for the resulting item. Use -2 to spawn result on the ground. Use -1 to place anywhere in the players inventory. Or use 0 (first ingredient) or 1 (second ingredient) to switch position with specific ingredient.
>
>> **ReplacesIngredient**
>> Sets the specific behavior for determining the spawn properties for the resulting item. Use -1 to do nothing or use 0 (first ingredient) or 1 (second ingredient) to transfer item properties, attachments etc.. from an specific ingredient to this resulted item.
