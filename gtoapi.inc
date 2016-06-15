/*

	About: api for using Open-GTO functions in FS
	Author: ziggi

*/

#if defined _gtoapi_included
	#endinput
#endif

#define _gtoapi_included

#if !defined _gtolib_included
	#error "Please include gtolib before gtoapi"
#endif

/*
	GivePlayerMoney
*/

stock gto_GivePlayerMoney(playerid, amount)
{
	return CallRemoteFunction("api_GivePlayerMoney", "dd", playerid, amount);
}
#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif

#define GivePlayerMoney api_GivePlayerMoney

/*
	SetPlayerHealth
*/

stock gto_SetPlayerHealth(playerid, Float:amount)
{
	return CallRemoteFunction("api_SetPlayerHealth", "df", playerid, amount);
}
#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif

#define SetPlayerHealth gto_SetPlayerHealth

/*
	GetMaxHealth
*/

stock GetMaxHealth(playerid, &Float:amount)
{
	if (!IsPlayerConnected(playerid)) {
		return 0;
	}

	amount = Float:CallRemoteFunction("api_GetMaxHealth", "d", playerid);
	return 1;
}

/*
	GivePlayerXP
*/

stock GivePlayerXP(playerid, xpamount, showtext = 0, showtd = 1)
{
	return CallRemoteFunction("api_GivePlayerXP", "dddd", playerid, amount, showtext, showtd);
}

/*
	GetPlayerLevel
*/

stock GetPlayerLevel(playerid)
{
	return CallRemoteFunction("api_GetPlayerLevel", "d", playerid);
}

/*
	GetVehicleModelCost
*/

stock Float:GetVehicleModelCost(model)
{
	return CallRemoteFunction("api_GetVehicleModelCost", "d", model);
}

/*
	GetVehicleModelMaxFuel
*/

stock Float:GetVehicleModelMaxFuel(model)
{
	return CallRemoteFunction("api_GetVehicleModelMaxFuel", "d", model);
}

/*
	SetVehicleFuel
*/

stock Float:SetVehicleFuel(vehicleid, Float:amount)
{
	return CallRemoteFunction("api_SetVehicleFuel", "df", vehicleid, amount);
}

/*
	GetVehicleFuel
*/

stock Float:GetVehicleFuel(vehicleid)
{
	return CallRemoteFunction("api_GetVehicleFuel", "d", vehicleid);
}

/*
	GiveVehicleFuel
*/

stock Float:GiveVehicleFuel(vehicleid, Float:amount)
{
	return CallRemoteFunction("api_GiveVehicleFuel", "df", vehicleid, amount);
}

/*
	GetModeVersion
*/

stock GetModeVersion(&major, &minor, &build, extra[], name[])
{
	GetModeInfo(MODE_INFO_VERSION, major, minor, build, extra, name);
}

/*
	GetModeName
*/

stock GetModeName(name[])
{
	GetModeInfo(MODE_INFO_NAME, .mode_name = name);
}

/*
	GetModeInfo
*/

stock GetModeInfo(type = MODE_INFO_VERSION, &major = 0, &minor = 0, &build = 0, extra[] = "", name[] = "", mode_name[] = "")
{
	CallRemoteFunction("api_GetModeInfo", "d", type);

	switch (type) {
		case MODE_INFO_NAME: {
			GetSVarString("mode_name", mode_name, MAX_NAME);
		}
		case MODE_INFO_VERSION: {
			major = GetSVarInt("version_major");
			minor = GetSVarInt("version_minor");
			build = GetSVarInt("version_build");
			GetSVarString("version_extra", extra, MAX_NAME);
			GetSVarString("version_name", name, MAX_NAME);
		}
	}
}
