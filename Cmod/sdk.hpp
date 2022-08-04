#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <cstdint>
#include <cstddef>
#include <string>
#include <thread>
#include <map>
#include "Memory.h"

namespace Offsets
{
	// easy paste offsets from https://apex.dumps.host/offsets
	const inline uintptr_t client_render_targets = 0x1fdf3a0;
	const inline uintptr_t ibase_client_dll = 0x19e1af0;
	const inline uintptr_t iclient_entity_list = 0x1fdebb0;
	const inline uintptr_t cprediction = 0x1fdebb8;
	const inline uintptr_t iv_model_render = 0x128b080;
	const inline uintptr_t vgui_system = 0x1f98b00;
	const inline uintptr_t iv_render_view = 0x7519c18;
	const inline uintptr_t iv_debug_overlay = 0x75b4da0;
	const inline uintptr_t iv_model_info_client = 0x7519c28;
	const inline uintptr_t iv_engine_client = 0x12799d8;
	const inline uintptr_t iv_engine_trace = 0x7519c30;
	const inline uintptr_t inetwork_string_table = 0x7519c40;
	const inline uintptr_t cnetwork_u64_table = 0x7519c48;
	const inline uintptr_t cinput = 0x1d95220;
	const inline uintptr_t cengine = 0x1292410;
	const inline uintptr_t iswapchain = 0xb912398;
	const inline uintptr_t cl_entitylist = 0x19fbf98;
	const inline uintptr_t local_entity_handle = 0x127d8bc;
	const inline uintptr_t local_player = 0x1dacd48;
	const inline uintptr_t global_vars = 0x135c910;
	const inline uintptr_t name_list = 0xb9f8340;
	const inline uintptr_t view_render = 0x7519c20; //need to get manuly
	const inline uintptr_t view_matrix = 0x11a210;  //need to get manuly
	const inline uintptr_t client_state = 0x135cc90;
	const inline uintptr_t sign_on_state = 0x135cd28;
	const inline uintptr_t level_name = 0x135ce40;
	const inline uintptr_t glow_enable = 0x10f;
	const inline uintptr_t glow_type = 0x2c0;
	const inline uintptr_t glow_color = 0x1d0;

	//might be out dated 
	const inline uintptr_t mp_gamemode = 0x01dd5c70;
	const inline uintptr_t in_attack = 0x074bae40;
	const inline std::uintptr_t m_nSkin = 0x0ea8;
	const inline uintptr_t gameTimeScale = 0x0128aa78;

	const inline std::uintptr_t m_iMaxHealth = 0x578;
	const inline std::uintptr_t m_ShieldHealthMax = 0x174;

	const inline std::uintptr_t m_helmetType = 0x4608; //----
	const inline std::uintptr_t m_armorType = 0x460c;  //----

	const inline std::uintptr_t m_weaponNameIndex = 0x16c4;
	const inline std::uintptr_t m_modBitfieldCurrent = 0x1864;
	const inline std::uintptr_t m_latestNonOffhandWeapons = 0x1abc; // read as uint8_t

	const inline std::uintptr_t OFFSET_THIRDPERSON = 0x019d2760 + 0x6c; // thirdperson_override + 0x6c
	const inline std::uintptr_t OFFSET_LASTOUTGOINGCOMMAND = client_state + 0x18CDC;

	const inline std::uintptr_t OFFSET_TEAM = 0x0448;		  // m_iTeamNum
	const inline std::uintptr_t OFFSET_HEALTH = 0x0438;		  // m_iHealth
	const inline std::uintptr_t OFFSET_SHIELD = 0x0170;		  // m_shieldHealth
	const inline std::uintptr_t OFFSET_NAME = 0x589;		  // m_iName
	const inline std::uintptr_t OFFSET_SIGN_NAME = 0x0580;	  // m_iSignifierName
	const inline std::uintptr_t OFFSET_ABS_VELOCITY = 0x140;  // m_vecAbsVelocity --
	const inline std::uintptr_t OFFSET_VISIBLE_TIME = 0x1b14; // CPlayer!lastVisibleTime //0x16e0
	const inline std::uintptr_t OFFSET_ZOOMING = 0x1c51;	  // m_bZooming

	const inline std::uintptr_t OFFSET_LIFE_STATE = 0x798;		 // m_lifeState, >0 = dead
	const inline std::uintptr_t OFFSET_BLEED_OUT_STATE = 0x2728; // m_bleedoutState, >0 = knocked//#define OFFSET_BLEED_OUT_STATE        0x26e8

	const inline std::uintptr_t OFFSET_ORIGIN = 0x14c;			   // FOR BASEENT ----
	const inline std::uintptr_t OFFSET_BONES = 0xF38;			   // m_bConstrainBetweenEndpoints
	const inline std::uintptr_t OFFSET_AIMPUNCH = 0x24a0;		   // m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle --
	const inline std::uintptr_t OFFSET_CAMERAPOS = 0x1f40;		   // CPlayer!camera_origin
	const inline std::uintptr_t OFFSET_VIEWANGLES = 0x259c - 0x14; // m_ammoPoolCapacity - 0x14
	const inline std::uintptr_t OFFSET_BREATH_ANGLES = OFFSET_VIEWANGLES - 0x10;
	const inline std::uintptr_t OFFSET_OBSERVER_MODE = 0x34c4;	  // m_iObserverMode
	const inline std::uintptr_t OFFSET_OBSERVING_TARGET = 0x34d0; // m_hObserverTarget
	const inline std::uintptr_t OFFSET_ITEM_ID = 0x16b8;		  // m_customScriptInt --

	const inline std::uintptr_t OFFSET_WEAPON = 0x1aac;			   // m_latestPrimaryWeapons
	const inline std::uintptr_t OFFSET_BULLET_SPEED = 0x1f38;	   // CWeaponX!m_flProjectileSpeed --
	const inline std::uintptr_t OFFSET_BULLET_SCALE = 0x1f40;	   // CWeaponX!m_flProjectileScale
	const inline std::uintptr_t OFFSET_ZOOM_FOV = 0x1728 + 0x00b8; // m_playerData + m_curZoomFOV
	const inline std::uintptr_t OFFSET_WEAPON_STATE = 0x16f4;	   // m_weapState
	const inline std::uintptr_t OFFSET_WEAPON_NAME_INDEX = 0x1884; // m_weaponNameIndex

	const inline std::uintptr_t OFFSET_GLOW_T1 = 0x262;			   // 16256 = enabled, 0 = disabled
	const inline std::uintptr_t OFFSET_GLOW_T2 = 0x2dc;			   // 1193322764 = enabled, 0 = disabled
	const inline std::uintptr_t OFFSET_GLOW_ENABLE = 0x9a1;		   // 7 = enabled, 2 = disabled
	const inline std::uintptr_t OFFSET_GLOW_THROUGH_WALLS = 0x3d0; // 2 = enabled, 5 = disabled

	const inline std::uintptr_t OFFSET_GLOW_DISTANCE = 0x3B4;
	const inline std::uintptr_t g_netChan = 0x1308B90;

	const inline std::uintptr_t GLOW_COLOR_R = 0x1D0; // OK Script_CopyHighlightState mov tcx n�7  / m_highlightParams + 24 (0x18)
	const inline std::uintptr_t GLOW_COLOR_G = 0x1D4; // OK Script_CopyHighlightState mov tcx n�7  / m_highlightParams + 24 (0x18)
	const inline std::uintptr_t GLOW_COLOR_B = 0x1D8; // OK Script_CopyHighlightState mov tcx n�7  / m_highlightParams + 24 (0x18)
													  //#define NUM_ENT_ENTRIES 0x10000
}
struct bone_t
{
	BYTE pad[0xCC];
	float x;
	BYTE pad2[0xC];
	float y;
	BYTE pad3[0xC];
	float z;
};

struct GlowMode
{
	int8_t GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel;
};

struct viewMatrix_t {
	float matrix[16];
};


struct globalVars
{
	uintptr_t localPlayer;
	uintptr_t entityList;
	uintptr_t nameList;
	uintptr_t currentAimTarget;
	uintptr_t glowPlayers;
	uintptr_t viewRenderer;
	//viewMatrix_t viewMatrix;
	//ImColor enemy = (255, 20, 20);
	//ImColor Team = (20, 255, 20);


	POINT windowWH{ 1920,1080 };

	bool noRecoil = true;
	float rcs = 100.f;


	bool aimbot = false;
	bool drawFOV = true;
	bool aimbotVis = true;
	bool aimbotline = true;
	float rcsaimbot = 100.f;
	float aimbotFOV = 200.f;
	float aimSmoothing = 100;

	int AimTarget = 8;
	int entityListNum = 100;

	bool esp = true;
	bool boxesp = false;
	bool enemy = true;
	bool lineEsp = false;
	bool NPCesp = false;
	bool skeliton = false;
	bool team = false;

	int espThickness = 2;
	float espDist = 1000;
	float espColor = (200, 10, 10);

	bool RainBow = false;
	bool menuActive = true;
	bool infoTab = false;

};
extern globalVars globals;