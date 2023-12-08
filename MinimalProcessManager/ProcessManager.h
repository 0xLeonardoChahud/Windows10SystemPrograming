#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>


class ProcessManager {
private:
	std::wstring processName;
	std::wstring imagePathName;
	DWORD processId;
	HANDLE hProcess;

	static void* ptrSuspendProcess;
	static void* ptrResumeProcess;
	
	void Cleanup(void);
	HANDLE getHandleFromPid(const DWORD pid);
	const std::wstring getImagePathName(const HANDLE hProcess);

public:
	ProcessManager(const DWORD pid = 0);
	~ProcessManager();
	void UpdateProcess(const DWORD pid);
	void UpdateProcess(const std::wstring& procName);

	
	// Getters
	const std::wstring& getProcessName(void) const { return this->processName; }
	const std::wstring& getImagePath(void) const { return this->imagePathName; }
	DWORD GetProcessId(void) const { return this->processId; }


	// Functionality
	DWORD DisplayProcessList(const bool filter = false, const std::wstring& procName = L"(none)") const;
	void DisplayProcessInfo(void) const;
	DWORD GetProcessIdByName(const std::wstring& procName);
	void TerminateProcess(DWORD exitCode = 0);
	void SuspendProcess(void);
	void ResumeProcess(void);

	


};
