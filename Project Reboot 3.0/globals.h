#pragma once

#include <atomic>
#include <map>
#include <string>

#include "inc.h"


#define ABOVE_S20
#define CLIENT_ONLY // only console reboot

namespace Globals
{

	extern inline auto Webhook = "";

	extern inline bool bCreative = false;
	extern inline bool bGoingToPlayEvent = false;
	extern inline bool bEnableAGIDs = true;
	extern inline bool bNoMCP = true;
	extern inline bool bLogProcessEvent = false;
	// extern inline bool bLateGame = false;
	extern inline std::atomic<bool> bLateGame(false);

	extern inline bool bInfiniteMaterials = true;
	extern inline bool bInfiniteAmmo = true;
	extern inline bool bShouldUseReplicationGraph = false;

		// Additional flags imported from Reboot-Ultimate
		extern inline int UPTime = 0;
		extern inline int tickTime = 0;

		extern inline bool bIsTickTiming = false;
		extern inline bool UPTimeStarted = false;

		extern inline bool bInfiniteRender = false;
		extern inline int InfiniteRenderMode = 0; // 0=default, 1=alt
		extern inline bool bUsePickaxeStutter = false;

		extern inline int AmountOfHealthSiphon = 50;
		extern inline bool bUseSiphon = false;

		extern inline bool bBotInvincible = false;
		extern inline bool bBotNames = false;
		extern inline bool bUseRandomSkins = true;
		extern inline int bBotHealth = 21;
		extern inline int bBotShield = 21;
		extern inline std::string BotPickaxeID = "WID_Harvest_HalloweenScythe_Athena_C_T01";
		extern inline std::string BotName = "";
		extern inline std::string BotSkin = "";

		extern inline bool bCustomLootpool = false;

		extern inline bool bAutoBusStart = false;


	extern inline bool bHitReadyToStartMatch = false;
	extern inline bool bInitializedPlaylist = false;
	extern inline bool bStartedListening = false;
	extern inline bool bAutoRestart = false; // doesnt work fyi
	extern inline bool bFillVendingMachines = true;
	extern inline bool bPrivateIPsAreOperator = true;
	extern inline int AmountOfListens = 0; // TODO: Switch to this for LastNum
	extern inline bool bDeveloperMode = false;
}

extern inline int NumToSubtractFromSquadId = 0; // I think 2?

extern inline std::string PlaylistName =
"/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo";
// "/Game/Athena/Playlists/gg/Playlist_Gg_Reverse.Playlist_Gg_Reverse";
// "/Game/Athena/Playlists/Playlist_DefaultDuo.Playlist_DefaultDuo";
// "/Game/Athena/Playlists/Playground/Playlist_Playground.Playlist_Playground";
// "/Game/Athena/Playlists/Carmine/Playlist_Carmine.Playlist_Carmine";
// "/Game/Athena/Playlists/Fill/Playlist_Fill_Solo.Playlist_Fill_Solo";
// "/Game/Athena/Playlists/Low/Playlist_Low_Solo.Playlist_Low_Solo";
// "/Game/Athena/Playlists/Bling/Playlist_Bling_Solo.Playlist_Bling_Solo";
// "/Game/Athena/Playlists/Creative/Playlist_PlaygroundV2.Playlist_PlaygroundV2";
// "/Game/Athena/Playlists/Ashton/Playlist_Ashton_Sm.Playlist_Ashton_Sm";
// "/Game/Athena/Playlists/BattleLab/Playlist_BattleLab.Playlist_BattleLab";
// "/MoleGame/Playlists/Playlist_MoleGame.Playlist_MoleGame"; // very experimental dont use