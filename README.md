# VALORANT_Analytic_Tools
 Some self-created tools for analyzing some information from VALORANT

DM-QOL_Analyzer.py is a python based simple tool for going through deathmatch VODs (Video on Demand) and selecting actions that happen to the user when they happen.
This tool is meant to help identify problems with the deathmatch enviroment beyond basic gameplay movement/mechanics. Actions that take away from the warm-up and improvment
means behind such a gamemode. Such as deaths/killing from behind and using sound to pre-fire enemies (footsteps only). Comparing that to how many "fair fights" were taken.

    Fair fights count as fights taken when both participants had the other player in their view/frame. Any other fights are considered unfair. Unless, the player turns to out of their
    view and kills someone without relying on footstep sound.  