// simplewall
// Copyright (c) 2016-2021 Henry++

#pragma once

_Ret_maybenull_
PVOID _app_getappinfo (_In_ PITEM_APP ptr_app, _In_ ENUM_INFO_DATA info_data);

_Ret_maybenull_
PVOID _app_getappinfobyhash (_In_ SIZE_T app_hash, _In_ ENUM_INFO_DATA info_data);

VOID _app_setappinfo (_In_ PITEM_APP ptr_app, _In_ ENUM_INFO_DATA info_data, _In_ PVOID value);
VOID _app_setappinfobyhash (_In_ SIZE_T app_hash, _In_ ENUM_INFO_DATA info_data, _In_ PVOID value);

_Ret_maybenull_
PVOID _app_getruleinfo (_In_ PITEM_RULE ptr_rule, _In_ ENUM_INFO_DATA info_data);

_Ret_maybenull_
PVOID _app_getruleinfobyid (_In_ SIZE_T idx, _In_ ENUM_INFO_DATA info_data);

_Ret_maybenull_
PITEM_APP _app_addapplication (_In_opt_ HWND hwnd, _In_ ENUM_TYPE_DATA type, _In_ LPCWSTR path, _In_opt_ PR_STRING display_name, _In_opt_ PR_STRING real_path);

PITEM_RULE _app_addrule (_In_opt_ PR_STRING name, _In_opt_ PR_STRING rule_remote, _In_opt_ PR_STRING rule_local, _In_ FWP_DIRECTION direction, _In_ UINT8 protocol, _In_ ADDRESS_FAMILY af);
PITEM_RULE_CONFIG _app_addruleconfigtable (_In_ PR_HASHTABLE hashtable, _In_ SIZE_T rule_hash, _In_opt_ PR_STRING name, _In_ BOOLEAN is_enabled);

_Ret_maybenull_
PITEM_RULE _app_getrulebyid (_In_ SIZE_T idx);

_Ret_maybenull_
PITEM_RULE _app_getrulebyhash (_In_ SIZE_T rule_hash);

SIZE_T _app_getnetworkapp (_In_ SIZE_T network_hash);

_Ret_maybenull_
PITEM_LOG _app_getlogitem (_In_ SIZE_T idx);

SIZE_T _app_getlogapp (_In_ SIZE_T idx);
COLORREF _app_getappcolor (_In_ INT listview_id, _In_ SIZE_T app_hash, _In_ BOOLEAN is_systemapp, _In_ BOOLEAN is_validconnection);

VOID _app_freeapplication (_In_ SIZE_T app_hash);

VOID _app_getcount (_Inout_ PITEM_STATUS status);

INT _app_getappgroup (_In_ PITEM_APP ptr_app);
INT _app_getnetworkgroup (_In_ PITEM_NETWORK ptr_network);
INT _app_getrulegroup (_In_ PITEM_RULE ptr_rule);
INT _app_getruleicon (_In_ PITEM_RULE ptr_rule);
COLORREF _app_getrulecolor (_In_ INT listview_id, _In_ SIZE_T rule_idx);

_Ret_maybenull_
PR_STRING _app_gettooltip (_In_ HWND hwnd, _In_ INT listview_id, _In_ INT item_id);

VOID _app_setappiteminfo (_In_ HWND hwnd, _In_ INT listview_id, _In_ INT item, _Inout_ PITEM_APP ptr_app);
VOID _app_setruleiteminfo (_In_ HWND hwnd, _In_ INT listview_id, _In_ INT item, _In_ PITEM_RULE ptr_rule, _In_ BOOLEAN include_apps);

VOID _app_ruleenable (_Inout_ PITEM_RULE ptr_rule, _In_ BOOLEAN is_enable, _In_ BOOLEAN is_createconfig);

BOOLEAN _app_ruleblocklistsetchange (_Inout_ PITEM_RULE ptr_rule, _In_ INT new_state);
BOOLEAN _app_ruleblocklistsetstate (_Inout_ PITEM_RULE ptr_rule, _In_ INT spy_state, _In_ INT update_state, _In_ INT extra_state);
VOID _app_ruleblocklistset (_In_opt_ HWND hwnd, _In_ INT spy_state, _In_ INT update_state, _In_ INT extra_state, _In_ BOOLEAN is_instantapply);

_Ret_maybenull_
PR_STRING _app_appexpandrules (_In_ SIZE_T app_hash, _In_ LPCWSTR delimeter);

_Ret_maybenull_
PR_STRING _app_rulesexpandapps (_In_ PITEM_RULE ptr_rule, _In_ BOOLEAN is_fordisplay, _In_ LPCWSTR delimeter);

_Ret_maybenull_
PR_STRING _app_rulesexpandrules (_In_ PR_STRING rule, _In_ LPCWSTR delimeter);

BOOLEAN _app_isappfromsystem (_In_ LPCWSTR path, _In_ SIZE_T app_hash);
BOOLEAN _app_isapphaveconnection (_In_ SIZE_T app_hash);
BOOLEAN _app_isapphavedrive (_In_ INT letter);
BOOLEAN _app_isapphaverule (_In_ SIZE_T app_hash, _In_ BOOLEAN is_countdisabled);
BOOLEAN _app_isappused (_In_ PITEM_APP ptr_app);
BOOLEAN _app_isappexists (_In_ PITEM_APP ptr_app);

VOID _app_openappdirectory (_In_ PITEM_APP ptr_app);

//BOOLEAN _app_profile_load_check_node (_In_ mxml_node_t* root_node, _In_ ENUM_TYPE_XML type);
BOOLEAN _app_profile_load_check (_In_ LPCWSTR path, _In_ ENUM_TYPE_XML type);

VOID _app_profile_load_fallback ();
//VOID _app_profile_load_helper (_In_ mxml_node_t* root_node, _In_ ENUM_TYPE_DATA type, _In_ UINT version);
VOID _app_profile_load_internal (_In_ LPCWSTR path, _In_ LPCWSTR resource_name, _Inout_opt_ PLONG64 ptimestamp);
VOID _app_profile_load (_In_opt_ HWND hwnd, _In_opt_ LPCWSTR path_custom);
VOID _app_profile_save ();
