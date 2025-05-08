What Is This?

This mod adds a refillable Zippo lighter to the game, complete with a flame and light source.

The Zippo can be refilled using gasoline from bottles and jerry cans.

It will slowly damage over time, so eventually players will need to find a new one.

It also converts the vanilla petrol lighter into essentially a non-refillable Zippo, with the flame and light source.

Server Owners:

To change how quickly the lighter is damaged from use, tweak the value 'varTotalLifetime' in config.cpp and repack.

Installation Instructions:

Install this mod like any other mod - copy it into your server folder and add it to your mods list. Make sure to copy the .bikey into your server keys if you're not using a server management tool like OmegaManager which does that automatically.

Make sure to merge the types.xml into your server types and adjust the item's lifetime, or the items will despawn on server restart and/or if no players are around. The types.xml file is in the mod folder and listed below.

This mod must be installed on both the server & client.

3D Model Credits:

The 3D models were free on Sketchfab under the CC Attribution-NonCommercial license.

Original Model: https://skfb.ly/6FUoz

Repack & Source Code:

You can repack this mod if you like, and do anything else you want with it for that matter. Just make sure to credit the original 3D model creator. The source code is on my GitHub at www.zenarchist.io

Enjoy!







Types.XML:

<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<types>
	<type name="ZenZippoLighter">
        <nominal>3</nominal>
        <lifetime>14400</lifetime>
        <restock>1800</restock>
        <min>2</min>
        <quantmin>20</quantmin>
        <quantmax>100</quantmax>
        <cost>100</cost>
        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
        <category name="tools"/>
        <tag name="shelves"/>
        <usage name="Village"/>
		<usage name="Hunting"/>
		<usage name="Military"/>
    </type>
	<type name="ZenZippoLighter_Peace">
        <nominal>3</nominal>
        <lifetime>14400</lifetime>
        <restock>1800</restock>
        <min>2</min>
        <quantmin>20</quantmin>
        <quantmax>100</quantmax>
        <cost>100</cost>
        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
        <category name="tools"/>
        <tag name="shelves"/>
        <usage name="Village"/>
		<usage name="Hunting"/>
		<usage name="Military"/>
    </type>
	<type name="ZenZippoLighter_Anarchy">
        <nominal>3</nominal>
        <lifetime>14400</lifetime>
        <restock>1800</restock>
        <min>2</min>
        <quantmin>20</quantmin>
        <quantmax>100</quantmax>
        <cost>100</cost>
        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
        <category name="tools"/>
        <tag name="shelves"/>
        <usage name="Village"/>
		<usage name="Hunting"/>
		<usage name="Military"/>
    </type>
	<type name="ZenZippoLighter_Zenarchist">
        <nominal>3</nominal>
        <lifetime>14400</lifetime>
        <restock>1800</restock>
        <min>2</min>
        <quantmin>20</quantmin>
        <quantmax>100</quantmax>
        <cost>100</cost>
        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
        <category name="tools"/>
        <tag name="shelves"/>
        <usage name="Village"/>
		<usage name="Hunting"/>
		<usage name="Military"/>
		<value name="Tier3"/>
    </type>
</types>