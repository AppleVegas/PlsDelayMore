#include "pch.h"
#include "plsdelay.h"
#include <winreg.h>
#include <chrono>

using days = std::chrono::duration
<int, std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>>;

bool DelayUntil(const char* fdate)
{
    

    const auto now = std::chrono::system_clock::now();   //const auto now = std::chrono::system_clock::now() + years{ 1 };
    time_t tim = std::chrono::system_clock::to_time_t(now);
    char buf[sizeof "0000-00-00T00:00:00Z"];
    strftime(buf, sizeof buf, "%FT%TZ", gmtime(&tim));
    unsigned char* cdate = reinterpret_cast<unsigned char*>(buf);
    DWORD szc = strlen((char*)cdate);

    const unsigned char* t = reinterpret_cast<const unsigned char*>(fdate);
    DWORD sz = strlen((char*)t);

	HKEY key;
	LSTATUS res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WindowsUpdate\\UX\\Settings", 0, KEY_SET_VALUE, &key);
    if (res != ERROR_SUCCESS)
    {  
        return false;
    }
    
    res = RegSetValueExA(key, "PauseFeatureUpdatesEndTime", 0, REG_SZ, t, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseQualityUpdatesEndTime", 0, REG_SZ, t, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseUpdatesExpiryTime", 0, REG_SZ, t, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseFeatureUpdatesStartTime", 0, REG_SZ, cdate, szc);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseQualityUpdatesStartTime", 0, REG_SZ, cdate, szc);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    RegCloseKey(key);
    return true;
}

bool DelayForYear()
{
    const auto now = std::chrono::system_clock::now();
    time_t tim = std::chrono::system_clock::to_time_t(now);
    char buf[sizeof "0000-00-00T00:00:00Z"];
    strftime(buf, sizeof buf, "%FT%TZ", gmtime(&tim));
    unsigned char* cdate = reinterpret_cast<unsigned char*>(buf);
    DWORD szc = strlen((char*)cdate);

    const auto thenn = std::chrono::system_clock::now() + days{ 365 };
    tim = std::chrono::system_clock::to_time_t(thenn);
    char buff[sizeof "0000-00-00T00:00:00Z"];
    strftime(buff, sizeof buff, "%FT%TZ", gmtime(&tim));
    unsigned char* fdate = reinterpret_cast<unsigned char*>(buff);
    DWORD sz = strlen((char*)fdate);

    HKEY key;
    LSTATUS res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WindowsUpdate\\UX\\Settings", 0, KEY_SET_VALUE, &key);
    if (res != ERROR_SUCCESS)
    {
        return false;
    }
    res = RegSetValueExA(key, "PauseFeatureUpdatesEndTime", 0, REG_SZ, fdate, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseQualityUpdatesEndTime", 0, REG_SZ, fdate, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseUpdatesExpiryTime", 0, REG_SZ, fdate, sz);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseFeatureUpdatesStartTime", 0, REG_SZ, cdate, szc);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    res = RegSetValueExA(key, "PauseQualityUpdatesStartTime", 0, REG_SZ, cdate, szc);
    if (res != ERROR_SUCCESS)
    {
        RegCloseKey(key);
        return false;
    }
    RegCloseKey(key);
    return true;
}

bool ResumeUpdates()
{
    HKEY key;
    LSTATUS res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\WindowsUpdate\\UX\\Settings", 0, KEY_ALL_ACCESS, &key);
    if (res != ERROR_SUCCESS)
    {
        return false;
    }
    RegDeleteValueA(key, "PauseFeatureUpdatesEndTime");
    RegDeleteValueA(key, "PauseQualityUpdatesEndTime");
    RegDeleteValueA(key, "PauseUpdatesExpiryTime");
    RegDeleteValueA(key, "PauseFeatureUpdatesStartTime");
    RegDeleteValueA(key, "PauseQualityUpdatesStartTime");
    RegCloseKey(key);
	return true;
}