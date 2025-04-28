int64_t sub_140001000(PWSTR arg1, PWSTR arg2)
{
    __chkstk(0x12c0);
    void var_12c8;
    int64_t rax_1 = __security_cookie ^ &var_12c8;
    int16_t var_1018;
    memset(&var_1018, 0, 0x800);
    HMODULE rax_2 = LoadLibraryW(u"MSVCP140.DLL");
    wchar16 var_1228[0x30];
    HMODULE rax_3;
    
    if (!rax_2)
    {
        PathCombineW(&var_1228, arg2, u"MSVCP140.DLL");
        rax_3 = LoadLibraryW(&var_1228);
    }
    
    if (!rax_2 && !rax_3)
        sub_1400035b8(&var_1018, 0x400, u"Microsoft Visual C++ 2015 Runtim…");
    else if (!LoadLibraryW(u"ucrtbase.dll"))
    {
        PathCombineW(&var_1228, arg2, u"ucrtbase.dll");
        
        if (!LoadLibraryW(&var_1228))
            sub_1400035b8(&var_1018, 0x400, u"Microsoft Visual C++ 2015 Runtim…");
    }
    
    if (!LoadLibraryW(u"XINPUT1_3.DLL"))
    {
        PathCombineW(&var_1228, arg2, u"XINPUT1_3.DLL");
        
        if (!LoadLibraryW(&var_1228))
            sub_1400035b8(&var_1018, 0x400, u"DirectX Runtime\n");
    }
    
    int64_t result;
    
    if (!var_1018)
        result = 0;
    else
    {
        void var_818;
        wsprintfW(&var_818, u"The following component(s) are r…", &var_1018);
        PathCombineW(&var_1228, arg1, u"Engine\Extras\Redist\en-us\UE4Pr…");
        
        if (GetFileAttributesW(&var_1228) != 0xffffffff)
        {
            sub_1400035b8(&var_818, 0x400, u"\nWould you like to install them…");
            
            if (MessageBoxW(nullptr, &var_818, nullptr, MB_YESNO) != IDNO)
            {
                SHELLEXECUTEINFOW execInfo;
                memset(&execInfo, 0, 0x70);
                execInfo.cbSize = 0x70;
                execInfo.lpFile = &var_1228;
                execInfo.fMask = 0x40;
                execInfo.nShow = 1;
                
                if (ShellExecuteExW(&execInfo))
                {
                    void* hProcess = execInfo.hProcess;
                    uint32_t exitCode[0x4];
                    exitCode[0] = 0;
                    WaitForSingleObject(hProcess, 0xffffffff);
                    GetExitCodeProcess(execInfo.hProcess, &exitCode);
                    CloseHandle(execInfo.hProcess);
                    
                    if (!exitCode[0])
                        result = 0;
                    else
                        result = 0x232c;
                }
                else
                    result = 0x232b;
            }
            else
                result = 0x232a;
        }
        else
        {
            MessageBoxW(nullptr, &var_818, nullptr, MB_OK);
            result = 0x2329;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_12c8);
    return result;
}

int128_t* sub_140001270(HMODULE arg1)
{
    PWSTR lpName;
    HRSRC hResInfo = FindResourceW(arg1, lpName, 0xa);
    
    if (hResInfo)
    {
        HGLOBAL hResData = LoadResource(arg1, hResInfo);
        
        if (hResData)
        {
            int128_t* rax = LockResource(hResData);
            uint64_t rbx_2 = SizeofResource(arg1, hResInfo) >> 1;
            uint64_t rcx_3 = rbx_2 + 1;
            uint64_t rax_2 = 2 * rcx_3;
            
            if ((2 * rcx_3) >> 0x40 != {0})
                rax_2 = -1;
            
            int128_t* result = j_operator new(rax_2);
            uint64_t __saved_rsi_1 = rbx_2 * 2;
            memcpy(result, rax, __saved_rsi_1);
            *(__saved_rsi_1 + result) = 0;
            return result;
        }
    }
    
    return 0;
}

uint64_t sub_140001330(PWSTR arg1)
{
    STARTUPINFOW startupInfo;
    memset(&startupInfo, 0, 0x68);
    startupInfo.cb = 0x68;
    PROCESS_INFORMATION var_98;
    __builtin_memset(&var_98, 0, 0x18);
    
    if (CreateProcessW(nullptr, arg1, nullptr, nullptr, 0, 0, nullptr, nullptr, &startupInfo, 
        &var_98))
    {
        WaitForSingleObject(var_98.hProcess, 0xffffffff);
        void* hProcess = var_98.hProcess;
        uint32_t exitCode = 0x232e;
        GetExitCodeProcess(hProcess, &exitCode);
        CloseHandle(var_98.hThread);
        CloseHandle(var_98.hProcess);
        return exitCode;
    }
    
    enum WIN32_ERROR rax_1 = GetLastError();
    int64_t rcx_1 = -1;
    
    do
        rcx_1 += 1;
     while (arg1[rcx_1]);
    
    uint64_t rax_2 = 2 * (rcx_1 + 0x32);
    
    if ((2 * (rcx_1 + 0x32)) >> 0x40 != {0})
        rax_2 = -1;
    
    PWSTR rax_3 = j_operator new(rax_2);
    wsprintfW(rax_3, u"Couldn't start:\n%s\nCreateProce…", arg1, rax_1);
    MessageBoxW(nullptr, rax_3, nullptr, MB_OK);
    j_sub_1400043fc(rax_3);
    return 0x232d;
}

uint64_t main(HMODULE arg1, int64_t arg2, int64_t arg3)
{
    void var_688;
    int64_t rax_1 = __security_cookie ^ &var_688;
    wchar16 var_238[0x108];
    GetModuleFileNameW(arg1, &var_238, 0x208);
    wchar16 var_658[0x108];
    PathCanonicalizeW(&var_658, &var_238);
    PathRemoveFileSpecW(&var_658);
    int128_t* rax_2 = sub_140001270(arg1);
    uint64_t result;
    
    if (rax_2)
    {
        int64_t rax_3 = -1;
        
        do
            rax_3 += 1;
         while (*(rax_2 + (rax_3 << 1)));
        
        int64_t rcx_3 = -1;
        
        do
            rcx_3 += 1;
         while (var_658[rcx_3]);
        
        int64_t rcx_4 = rcx_3 + rax_3 + 0x14;
        uint64_t rax_5 = 2 * rcx_4;
        
        if ((2 * rcx_4) >> 0x40 != {0})
            rax_5 = -1;
        
        PWSTR rax_6 = j_operator new(rax_5);
        wsprintfW(rax_6, u"%s\%s", &var_658, rax_2);
        wchar16 var_448[0x108];
        PathCanonicalizeW(&var_448, rax_6);
        j_sub_1400043fc(rax_6);
        PathRemoveFileSpecW(&var_448);
        int128_t* rax_7 = sub_140001270(arg1);
        int64_t rcx_11 = -1;
        
        do
            rcx_11 += 1;
         while (*(arg3 + (rcx_11 << 1)));
        
        int64_t rax_8 = -1;
        
        do
            rax_8 += 1;
         while (*(rax_7 + (rax_8 << 1)));
        
        int64_t rax_9 = -1;
        
        do
            rax_9 += 1;
         while (*(rax_2 + (rax_9 << 1)));
        
        int64_t rdx_5 = -1;
        
        do
            rdx_5 += 1;
         while (var_658[rdx_5]);
        
        int64_t rcx_14 = rcx_11 + rax_8 + rax_9 + rdx_5 + 0x14;
        uint64_t rax_10 = 2 * rcx_14;
        
        if ((2 * rcx_14) >> 0x40 != {0})
            rax_10 = -1;
        
        PWSTR param0 = j_operator new(rax_10);
        wsprintfW(param0, u""%s\%s" %s %s", &var_658, rax_2, rax_7, arg3);
        j_sub_1400043fc(rax_7);
        j_sub_1400043fc(rax_2);
        int32_t result_2 = sub_140001000(&var_658, &var_448);
        int32_t result_1 = result_2;
        PWSTR param0_1 = param0;
        int32_t result_3;
        
        if (!result_2)
        {
            result_3 = sub_140001330(param0_1);
            result_1 = result_3;
            param0_1 = param0;
        }
        
        if (!result_2 && !result_3)
        {
            j_sub_1400043fc(param0_1);
            result = 0;
        }
        else
        {
            j_sub_1400043fc(param0_1);
            result = result_1;
        }
    }
    else
    {
        MessageBoxW(nullptr, u"This program is used for package…", nullptr, MB_OK);
        result = 0x2328;
    }
    
    __security_check_cookie(rax_1 ^ &var_688);
    return result;
}

int64_t initialize_legacy_wide_specifiers()
{
    data_140016980 |= 4;
    data_140016988 |= 2;
    return 0;
}

int64_t sub_1400016d4() __pure
{
    return &data_140016980;
}

int64_t sub_1400016dc() __pure
{
    return &data_140016988;
}

int64_t j_operator new(uint64_t arg1)
{
    /* tailcall */
    return operator new(arg1);
}

int64_t j_sub_1400043fc(int64_t arg1)
{
    /* tailcall */
    return j_sub_1400043fc(arg1);
}

int64_t __GSHandlerCheck(int64_t arg1, int64_t arg2, int64_t arg3, void* arg4)
{
    __GSHandlerCheckCommon(arg2, arg4, *(arg4 + 0x38));
    return 1;
}

int64_t __GSHandlerCheckCommon(int64_t arg1, void* arg2, int32_t* arg3)
{
    int64_t r9 = arg1;
    int64_t r10 = arg1;
    
    if (*arg3 & 4)
        r10 = (arg3[1] + arg1) & -(arg3[2]);
    
    void* rcx_2 = *(*(arg2 + 0x10) + 8) + *(arg2 + 8);
    
    if (*(rcx_2 + 3) & 0xf)
        r9 += *(rcx_2 + 3) & 0xfffffff0;
    
    /* tailcall */
    return __security_check_cookie(r9 ^ *((*arg3 & 0xfffffff8) + r10));
}

void __chkstk(int64_t arg1 @ rax)
{
    void arg_8;
    void* r10 = &arg_8 - arg1;
    
    if (&arg_8 < arg1)
        r10 = nullptr;
    
    TEB* gsbase;
    void* StackLimit = gsbase->NtTib.StackLimit;
    
    if (r10 < StackLimit)
    {
        r10 &= 0xf000;
        
        do
        {
            StackLimit -= 0x1000;
            *StackLimit = 0;
        } while (r10 != StackLimit);
    }
}

int64_t __security_check_cookie(int64_t arg1)
{
    if (arg1 == __security_cookie)
    {
        int64_t rcx = ROLQ(arg1, 0x10);
        
        if (!(rcx & 0xffff))
            return;
        
        arg1 = RORQ(rcx, 0x10);
    }
    
    /* tailcall */
    return __report_gsfailure(arg1);
}

int64_t pre_c_initialization()
{
    sub_1400037cc(2);
    _set_fmode(0x4000);
    data_14001735c = 0;
    
    if (!__scrt_initialize_onexit_tables(1))
    {
        __scrt_fastfail(7);
        breakpoint();
    }
    
    sub_140002218();
    atexit(sub_140002264);
    
    if (_configure_wide_argv(1))
    {
        __scrt_fastfail(7);
        breakpoint();
    }
    
    sub_140001fa4();
    
    if (sub_140001fd4())
        __setusermatherr(sub_140001f90);
    
    _configthreadlocale(0);
    
    if (sub_1400048cc())
        j_common_initialize_environment_nolock<wchar_t>();
    
    return 0;
}

int64_t post_pgo_initialization()
{
    __scrt_initialize_default_local_stdio_options();
    return 0;
}

int64_t pre_cpp_initialization()
{
    sub_1400021d0();
    /* tailcall */
    return sub_140004354(0);
}

uint64_t sub_1400018fc()
{
    if (!__scrt_initialize_crt(1))
    {
        __scrt_fastfail(7);
        breakpoint();
    }
    
    int64_t rdi;
    rdi = 0;
    char var_18 = 0;
    int64_t rbx;
    rbx = __scrt_acquire_startup_lock();
    int32_t rcx = data_140016f00;
    
    if (rcx == 1)
        rcx = __scrt_fastfail(7);
    
    if (rcx)
    {
        rdi = 1;
        char var_18_1 = 1;
    }
    else
    {
        data_140016f00 = 1;
        
        if (sub_140003eb0(&data_14000c2d0, &data_14000c308))
            return 0xff;
        
        sub_140003e4c(&data_14000c2b8, &data_14000c2c8);
        data_140016f00 = 2;
    }
    
    rcx = rbx;
    __scrt_release_startup_lock(rcx);
    
    if (data_140017c58 && __scrt_is_nonwritable_in_current_image(&data_140017c58))
    {
        void (* rbx_1)() = data_140017c58;
        j__guard_check_icall(rbx_1);
        rbx_1(0, 2, 0);
    }
    
    if (data_140017c50 && __scrt_is_nonwritable_in_current_image(&data_140017c50))
        _register_thread_local_exe_atexit_callback(data_140017c50);
    
    __scrt_get_show_window_mode();
    uint32_t rax_8 = main(&__dos_header, 0, common_wincmdln<wchar_t>());
    
    if (!__scrt_is_managed_app())
        sub_1400041e8(rax_8);
    
    if (!rdi)
        _cexit();
    
    __scrt_uninitialize_crt(1, 0);
    return rax_8;
}

uint64_t sub_140001a3c(uint32_t arg1 @ rax, char arg2, int64_t arg3, int64_t arg4)
{
    if (!__scrt_is_managed_app())
    {
        sub_140004198(arg1);
        breakpoint();
    }
    
    if (!arg2)
        sub_140004178();
    
    return arg1;
}

int64_t _start()
{
    __security_init_cookie();
    /* tailcall */
    return sub_1400018fc();
}

int64_t operator new(uint64_t arg1)
{
    uint64_t rbx = arg1;
    
    while (true)
    {
        int64_t result = j_sub_140004aa0(arg1);
        
        if (result)
            return result;
        
        if (!sub_140004390(rbx))
            break;
        
        arg1 = rbx;
    }
    
    if (rbx == -1)
    {
        __scrt_throw_std_bad_alloc();
        /* no return */
    }
    
    stdext::threads::_Throw_lock_error();
    /* no return */
}

int64_t j_sub_1400043fc(int64_t arg1)
{
    /* tailcall */
    return sub_1400043fc(arg1);
}

void __raise_securityfailure(EXCEPTION_POINTERS* arg1) __noreturn
{
    SetUnhandledExceptionFilter(0);
    UnhandledExceptionFilter(arg1);
    /* tailcall */
    return TerminateProcess(GetCurrentProcess(), 0xc0000409);
}

void __report_gsfailure(uint64_t stack_cookie) __noreturn
{
    uint64_t stack_cookie_1 = stack_cookie;
    
    if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
        trap(0xd);
    
    capture_previous_context(&data_140016a30);
    data_140016b28 = __return_addr;
    data_140016ac8 = &stack_cookie_1;
    data_1400169a0 = data_140016b28;
    data_140016ab0 = stack_cookie_1;
    data_140016990 = 0xc0000409;
    data_140016994 = 1;
    data_1400169a8 = 1;
    data_1400169b0 = 2;
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t var_10 = data_140016008;
    __raise_securityfailure(&data_14000c6a0);
    /* no return */
}

int64_t sub_140001bc0() __pure
{
    return;
}

IMAGE_RUNTIME_FUNCTION_ENTRY* capture_previous_context(CONTEXT* arg1)
{
    RtlCaptureContext(arg1);
    uint64_t Rip = arg1->Rip;
    IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry;
    
    for (int32_t i = 0; i < 2; i += 1)
    {
        uint64_t ImageBase;
        FunctionEntry = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
        
        if (!FunctionEntry)
            break;
        
        uint64_t EstablisherFrame;
        void HandlerData;
        FunctionEntry = RtlVirtualUnwind(UNW_FLAG_NHANDLER, ImageBase, Rip, FunctionEntry, arg1, 
            &HandlerData, &EstablisherFrame, nullptr);
    }
    
    return FunctionEntry;
}

int64_t __scrt_acquire_startup_lock()
{
    int64_t result;
    
    if (!sub_140002624())
    {
        label_140001c6a:
        result = 0;
    }
    else
    {
        TEB* gsbase;
        void* StackBase = gsbase->NtTib.Self->NtTib.StackBase;
        
        do
        {
            result = 0;
            bool z_1;
            
            if (0 == data_140016f08)
            {
                data_140016f08 = StackBase;
                z_1 = true;
            }
            else
            {
                result = data_140016f08;
                z_1 = false;
            }
            
            if (z_1)
                goto label_140001c6a;
        } while (StackBase != result);
        
        result = 1;
    }
    
    return result;
}

int64_t __scrt_initialize_crt(int32_t arg1)
{
    char rax = data_140016f40;
    
    if (!arg1)
        rax = 1;
    
    data_140016f40 = rax;
    int64_t xcr0;
    __isa_available_init(xcr0);
    
    if (__vcrt_initialize())
    {
        if (sub_140004a18())
            return 1;
        
        __vcrt_uninitialize(0);
    }
    
    return 0;
}

int64_t __scrt_initialize_onexit_tables(int32_t arg1)
{
    if (arg1 > 1)
    {
        __scrt_fastfail(5);
        breakpoint();
    }
    
    int32_t result;
    
    if (!sub_140002624() || arg1)
    {
        uint64_t __security_cookie_1 = __security_cookie;
        result = 1;
        int64_t r8_2 = RORQ(-1, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
        int64_t var_20_1 = r8_2;
        data_140016f10 = r8_2;
        int64_t var_20_2 = r8_2;
        data_140016f20 = r8_2;
        data_140016f28 = r8_2;
        data_140016f38 = r8_2;
    }
    else if (!sub_1400047fc(&data_140016f10))
        result = !sub_1400047fc(&data_140016f28);
    else
        result = 0;
    
    return result;
}

uint64_t __scrt_is_nonwritable_in_current_image(int64_t arg1)
{
    struct Section_Header* const rdx_1 = &__section_headers;
    
    while (true)
    {
        struct Section_Header* const var_18_1 = rdx_1;
        
        if (rdx_1 == &data_140000318)
        {
            rdx_1 = nullptr;
            break;
        }
        
        uint64_t virtualAddress = rdx_1->virtualAddress;
        
        if (arg1 - &__dos_header >= virtualAddress
                && arg1 - &__dos_header < rdx_1->virtualSize + virtualAddress)
            break;
        
        rdx_1 = &rdx_1[1];
    }
    
    uint64_t result;
    
    if (!rdx_1)
        result = 0;
    else if (rdx_1->characteristics >= 0)
        result = 1;
    else
        result = 0;
    
    return result;
}

int64_t __scrt_release_startup_lock(char arg1)
{
    int64_t rbx;
    rbx = arg1;
    int32_t result = sub_140002624();
    
    if (result && !rbx)
    {
        data_140016f08;
        data_140016f08 = 0;
    }
    
    return result;
}

int64_t __scrt_uninitialize_crt(char arg1, char arg2)
{
    int64_t rbx;
    rbx = arg1;
    
    if (!data_140016f40 || !arg2)
    {
        sub_140004a2c();
        __vcrt_uninitialize(rbx);
    }
    
    int64_t result;
    result = 1;
    return result;
}

int64_t _onexit(int64_t arg1)
{
    uint64_t __security_cookie_1 = __security_cookie;
    int32_t rax;
    
    if (RORQ(__security_cookie_1 ^ *data_140016f10, __security_cookie_1 & 0x3f) != -1)
        rax = sub_14000483c(&data_140016f10, arg1);
    else
        rax = sub_1400047b0(arg1);
    
    if (!rax)
        return arg1;
    
    return 0;
}

uint64_t atexit(int64_t arg1)
{
    int64_t rax = _onexit(arg1);
    int32_t rax_1 = -(rax);
    return -((rax_1 - rax_1)) - 1;
}

uint64_t __security_init_cookie()
{
    FILETIME systemTimeAsFileTime;
    systemTimeAsFileTime.dwLowDateTime = 0;
    systemTimeAsFileTime.dwHighDateTime = 0;
    uint64_t __security_cookie_1 = __security_cookie;
    
    if (__security_cookie_1 == 0x2b992ddfa232)
    {
        GetSystemTimeAsFileTime(&systemTimeAsFileTime);
        int64_t rax;
        rax = systemTimeAsFileTime.dwLowDateTime;
        *rax[4] = systemTimeAsFileTime.dwHighDateTime;
        int64_t arg_8 = rax;
        uint64_t rax_2 = GetCurrentThreadId();
        arg_8 ^= rax_2;
        uint64_t rax_4 = GetCurrentProcessId();
        arg_8 ^= rax_4;
        int64_t performanceCount;
        QueryPerformanceCounter(&performanceCount);
        __security_cookie_1 =
            (performanceCount << 0x20 ^ performanceCount ^ arg_8 ^ &arg_8) & 0xffffffffffff;
        
        if (__security_cookie_1 == 0x2b992ddfa232)
            __security_cookie_1 = 0x2b992ddfa233;
        
        __security_cookie = __security_cookie_1;
    }
    
    uint64_t result = ~__security_cookie_1;
    data_140016008 = result;
    return result;
}

int64_t sub_140001f90() __pure
{
    return 0;
}

int64_t sub_140001f94() __pure
{
    return 1;
}

int64_t sub_140001f9c() __pure
{
    return 0x4000;
}

int64_t sub_140001fa4()
{
    /* tailcall */
    return InitializeSListHead(&data_140016f50);
}

void _guard_check_icall(void (* arg1)()) __pure
{
    return;
}

int64_t __scrt_initialize_default_local_stdio_options()
{
    data_140016980 |= 4;
    data_140016988 |= 2;
    return &data_140016988;
}

int64_t sub_140001fd4()
{
    int64_t result;
    result = !data_140016014;
    return result;
}

int64_t sub_140001fe0() __pure
{
    return &data_140017c58;
}

int64_t sub_140001fe8() __pure
{
    return &data_140017c50;
}

int64_t sub_140001ff0()
{
    data_140016f60 = 0;
}

int32_t __scrt_fastfail(int32_t arg1)
{
    if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
        trap(0xd);
    
    data_140016f60 = 0;
    CONTEXT ContextRecord;
    memset(&ContextRecord, 0, 0x4d0);
    RtlCaptureContext(&ContextRecord);
    uint64_t Rip = ContextRecord.Rip;
    uint64_t ImageBase;
    IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
    uint64_t EstablisherFrame;
    void HandlerData;
    
    if (FunctionEntry)
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, ImageBase, Rip, FunctionEntry, &ContextRecord, 
            &HandlerData, &EstablisherFrame, nullptr);
    ContextRecord.Rip = __return_addr;
    int64_t __saved_rbx;
    ContextRecord.Rsp = &__saved_rbx;
    int32_t var_578;
    memset(&var_578, 0, 0x98);
    void* const __return_addr_1 = __return_addr;
    var_578 = 0x40000015;
    int32_t var_574 = 1;
    bool cond:0 = IsDebuggerPresent() == 1;
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = &var_578;
    Rip = cond:0;
    ExceptionInfo.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(nullptr);
    int32_t result = UnhandledExceptionFilter(&ExceptionInfo);
    
    if (!result)
    {
        char temp0_1 = Rip;
        Rip = -(Rip);
        result = result - result;
        data_140016f60 &= result;
    }
    
    return result;
}

uint64_t __scrt_get_show_window_mode()
{
    STARTUPINFOW startupInfo;
    memset(&startupInfo, 0, 0x68);
    GetStartupInfoW(&startupInfo);
    
    if (startupInfo.dwFlags & 1)
        return startupInfo.wShowWindow;
    
    return 0xa;
}

HMODULE __scrt_is_managed_app()
{
    HMODULE result = GetModuleHandleW(nullptr);
    
    if (result && result->unused == 0x5a4d)
    {
        result *= 2;
        
        if (result->unused != 0x4550 || *(result + 0x18) != 0x20b || result <= 0xe)
            result = 0;
        else
            result = result;
    }
    else
        result = 0;
    
    return result;
}

int64_t sub_1400021d0()
{
    /* tailcall */
    return SetUnhandledExceptionFilter(sub_1400021e0);
}

int64_t sub_1400021e0(int64_t* arg1)
{
    int32_t* rax = *arg1;
    
    if (*rax == 0xe06d7363 && rax[6] == 4)
    {
        int32_t rcx = rax[8];
        
        if (rcx - 0x19930520 <= 2 || rcx == 0x1994000)
        {
            sub_140004a40();
            /* no return */
        }
    }
    
    return 0;
}

void sub_140002218()
{
    for (void* const i = &data_140013bd0; i < &data_140013bd0; i += 8)
    {
        void (* rdi_1)() = *i;
        
        if (rdi_1)
        {
            j__guard_check_icall(rdi_1);
            rdi_1(rdi_1);
        }
    }
}

void sub_140002264()
{
    for (void* const i = &data_140013be0; i < &data_140013be0; i += 8)
    {
        void (* rdi_1)() = *i;
        
        if (rdi_1)
        {
            j__guard_check_icall(rdi_1);
            rdi_1(rdi_1);
        }
    }
}

void j__guard_check_icall(void (* arg1)())
{
    /* tailcall */
    return _guard_check_icall(arg1);
}

struct std::exception::VTable** std::__non_rtti_object::__non_rtti_object(struct std::exception::VTable** arg1, void* arg2)
{
    *arg1 = &std::exception::`vftable';
    arg1[1] = 0;
    arg1[2] = 0;
    __std_exception_copy(arg2 + 8, &arg1[1]);
    *arg1 = &std::bad_alloc::`vftable'{for `std::exception'};
    return arg1;
}

struct std::exception::std::bad_alloc::VTable** std::bad_exception::bad_exception(struct std::exception::std::bad_alloc::VTable** arg1)
{
    arg1[2] = 0;
    arg1[1] = "bad allocation";
    *arg1 = &std::bad_alloc::`vftable'{for `std::exception'};
    return arg1;
}

struct std::exception::VTable** Concurrency::invalid_link_target::invalid_link_target(struct std::exception::VTable** arg1, void* arg2)
{
    *arg1 = &std::exception::`vftable';
    arg1[1] = 0;
    arg1[2] = 0;
    __std_exception_copy(arg2 + 8, &arg1[1]);
    *arg1 = &std::bad_array_new_length::`vftable'{for `std::bad_alloc'};
    return arg1;
}

struct std::bad_alloc::std::bad_array_new_length::VTable** std::bad_cast::bad_cast(struct std::bad_alloc::std::bad_array_new_length::VTable** arg1)
{
    arg1[2] = 0;
    arg1[1] = "bad array new length";
    *arg1 = &std::bad_array_new_length::`vftable'{for `std::bad_alloc'};
    return arg1;
}

struct std::exception::VTable** Concurrency::invalid_multiple_scheduling::invalid_multiple_scheduling(struct std::exception::VTable** arg1, void* arg2)
{
    *arg1 = &std::exception::`vftable';
    arg1[1] = 0;
    arg1[2] = 0;
    __std_exception_copy(arg2 + 8, &arg1[1]);
    return arg1;
}

int64_t Concurrency::invalid_oversubscribe_operation::~invalid_oversubscribe_operation(struct std::exception::VTable** arg1)
{
    *arg1 = &std::exception::`vftable';
    /* tailcall */
    return __std_exception_destroy(&arg1[1]);
}

struct std::exception::VTable** std::bad_typeid::`scalar deleting destructor'(struct std::exception::VTable** arg1, char arg2)
{
    *arg1 = &std::exception::`vftable';
    __std_exception_destroy(&arg1[1]);
    
    if (arg2 & 1)
        j_sub_1400043fc(arg1);
    
    return arg1;
}

void stdext::threads::_Throw_lock_error() __noreturn
{
    struct std::exception::std::bad_alloc::VTable* exceptionObject;
    std::bad_exception::bad_exception(&exceptionObject);
    _CxxThrowException(&exceptionObject, &data_140014670);
    /* no return */
}

void __scrt_throw_std_bad_alloc() __noreturn
{
    struct std::bad_alloc::std::bad_array_new_length::VTable* exceptionObject;
    std::bad_cast::bad_cast(&exceptionObject);
    _CxxThrowException(&exceptionObject, &data_1400146f8);
    /* no return */
}

char const* const sub_140002448(void* arg1)
{
    if (*(arg1 + 8))
        return *(arg1 + 8);
    
    return "Unknown exception";
}

int64_t __isa_available_init(int64_t arg1 @ xcr0)
{
    char var_20 = 0;
    data_14001601c = 2;
    int32_t temp0;
    int32_t temp1;
    int32_t temp2;
    int32_t temp3;
    temp0 = __cpuid(0, 0);
    data_140016018 = 1;
    int32_t r8_2 = data_140016f64;
    int32_t temp0_1;
    int32_t temp1_1;
    int32_t temp2_1;
    int32_t temp3_1;
    temp0_1 = __cpuid(1, 0);
    int32_t var_18 = temp0_1;
    int32_t var_10 = temp2_1;
    int32_t var_14 = temp1_1;
    int32_t var_c = temp3_1;
    
    if (!((temp3 ^ 0x49656e69) | (temp2 ^ 0x6c65746e) | (temp1 ^ 0x756e6547)))
    {
        data_140016020 = -1;
        r8_2 |= 4;
        int32_t rax_2 = temp0_1 & 0xfff3ff0;
        data_140016f64 = r8_2;
        
        if (rax_2 == 0x106c0 || rax_2 == 0x20660 || rax_2 == 0x20670)
        {
            r8_2 |= 1;
            data_140016f64 = r8_2;
        }
        else
        {
            uint64_t rax_3 = rax_2 - 0x30650;
            
            if (rax_3 <= 0x20 && TEST_BITQ(0x100010001, rax_3))
            {
                r8_2 |= 1;
                data_140016f64 = r8_2;
            }
        }
    }
    
    if (!((temp1 ^ 0x68747541) | (temp3 ^ 0x69746e65) | (temp2 ^ 0x444d4163))
        && (temp0_1 & 0xff00f00) >= 0x600f00)
    {
        r8_2 |= 4;
        data_140016f64 = r8_2;
    }
    
    int32_t var_28 = temp3_1;
    int32_t var_24 = temp2_1;
    
    if (temp0 >= 7)
    {
        int32_t temp0_2;
        int32_t temp1_2;
        int32_t temp2_2;
        int32_t temp3_2;
        temp0_2 = __cpuid(7, 0);
        int32_t var_18_1 = temp0_2;
        int32_t var_14_1 = temp1_2;
        int32_t var_10_1 = temp2_2;
        int32_t var_c_1 = temp3_2;
        var_20 = temp1_2;
        
        if (TEST_BITD(temp1_2, 9))
            data_140016f64 = r8_2 | 2;
    }
    
    if (TEST_BITD(temp2_1, 0x14))
    {
        data_140016018 = 2;
        data_14001601c = 6;
        
        if (TEST_BITD(temp2_1, 0x1b) && TEST_BITD(temp2_1, 0x1c))
        {
            int32_t temp0_3;
            char temp1_3;
            temp0_3 = _xgetbv(0, arg1);
            
            if (((temp0_3 << 0x20 | temp1_3) & 6) == 6)
            {
                int32_t rax_8 = data_14001601c | 8;
                data_140016018 = 3;
                data_14001601c = rax_8;
                
                if (var_20 & 0x20)
                {
                    data_140016018 = 5;
                    data_14001601c = rax_8 | 0x20;
                }
            }
        }
    }
    
    return 0;
}

int64_t sub_140002624()
{
    int64_t result;
    result = data_140017c48;
    return result;
}

struct type_info::VTable** type_info::`scalar deleting destructor'(struct type_info::VTable** arg1, char arg2)
{
    *arg1 = &type_info::`vftable';
    
    if (arg2 & 1)
        j_sub_1400043fc(arg1);
    
    return arg1;
}

int128_t* memcpy(int128_t* arg1, int128_t* arg2, void* __saved_rsi)
{
    if (__saved_rsi > 0x10)
    {
        int128_t zmm1;
        
        if (__saved_rsi <= 0x20)
        {
            zmm1 = *(__saved_rsi + arg2 - 0x10);
            *arg1 = *arg2;
            *(__saved_rsi + arg1 - 0x10) = zmm1;
            return arg1;
        }
        
        int128_t* rdx = arg2 - arg1;
        int128_t zmm0;
        
        if (arg2 < arg1 && arg1 < arg2 + __saved_rsi)
        {
            int64_t rcx_21 = arg1 + __saved_rsi;
            zmm0 = *(rdx + rcx_21 - 0x10);
            int128_t* rcx_22 = rcx_21 - 0x10;
            void* __saved_rsi_15 = __saved_rsi - 0x10;
            
            if (rcx_22 & 0xf)
            {
                int128_t* rax_8 = rcx_22;
                rcx_22 &= 0xfffffffffffffff0;
                zmm1 = zmm0;
                zmm0 = *(rdx + rcx_22);
                *rax_8 = zmm1;
                __saved_rsi_15 = rcx_22 - arg1;
            }
            
            uint64_t r9_10 = __saved_rsi_15 >> 7;
            
            if (r9_10)
            {
                *rcx_22 = zmm0;
                
                while (true)
                {
                    zmm0 = *(rdx + rcx_22 - 0x10);
                    zmm1 = *(rdx + rcx_22 - 0x20);
                    rcx_22 -= 0x80;
                    rcx_22[7] = zmm0;
                    rcx_22[6] = zmm1;
                    zmm1 = *(rdx + rcx_22 + 0x40);
                    uint64_t temp2_1 = r9_10;
                    r9_10 -= 1;
                    rcx_22[5] = *(rdx + rcx_22 + 0x50);
                    rcx_22[4] = zmm1;
                    zmm1 = *(rdx + rcx_22 + 0x20);
                    rcx_22[3] = *(rdx + rcx_22 + 0x30);
                    rcx_22[2] = zmm1;
                    zmm0 = *(rdx + rcx_22 + 0x10);
                    zmm1 = *(rdx + rcx_22);
                    
                    if (temp2_1 == 1)
                        break;
                    
                    rcx_22[1] = zmm0;
                    *rcx_22 = zmm1;
                }
                
                rcx_22[1] = zmm0;
                __saved_rsi_15 &= 0x7f;
                zmm0 = zmm1;
            }
            
            uint64_t i_3 = __saved_rsi_15 >> 4;
            
            if (i_3)
            {
                uint64_t i;
                
                do
                {
                    *rcx_22 = zmm0;
                    rcx_22 -= 0x10;
                    zmm0 = *(rdx + rcx_22);
                    i = i_3;
                    i_3 -= 1;
                } while (i != 1);
            }
            
            if (__saved_rsi_15 & 0xf)
                *arg1 = *arg2;
            
            *rcx_22 = zmm0;
            return arg1;
        }
        
        void* rcx_19;
        void* __saved_rsi_13;
        
        if (__saved_rsi <= 0x80)
        {
            zmm0 = *(rdx + arg1);
            rcx_19 = &arg1[1];
            __saved_rsi_13 = __saved_rsi - 0x10;
        }
        else
        {
            if (TEST_BITD(data_140016f64, 1))
            {
                __builtin_memcpy(arg1, arg2, __saved_rsi);
                return arg1;
            }
            
            zmm0 = *(rdx + arg1);
            rcx_19 = &arg1[1];
            
            if (arg1 & 0xf)
            {
                zmm1 = zmm0;
                void* rcx_20 = rcx_19 & 0xfffffffffffffff0;
                zmm0 = *(rdx + rcx_20);
                rcx_19 = rcx_20 + 0x10;
                *arg1 = zmm1;
            }
            
            __saved_rsi_13 = __saved_rsi + arg1 - rcx_19;
            uint64_t r9_7 = __saved_rsi_13 >> 7;
            
            if (r9_7)
            {
                *(rcx_19 - 0x10) = zmm0;
                
                if (r9_7 <= data_140016020)
                {
                    while (true)
                    {
                        zmm0 = *(rdx + rcx_19);
                        zmm1 = *(rdx + rcx_19 + 0x10);
                        rcx_19 += 0x80;
                        *(rcx_19 - 0x80) = zmm0;
                        *(rcx_19 - 0x70) = zmm1;
                        zmm1 = *(rdx + rcx_19 - 0x50);
                        uint64_t temp3_1 = r9_7;
                        r9_7 -= 1;
                        *(rcx_19 - 0x60) = *(rdx + rcx_19 - 0x60);
                        *(rcx_19 - 0x50) = zmm1;
                        zmm1 = *(rdx + rcx_19 - 0x30);
                        *(rcx_19 - 0x40) = *(rdx + rcx_19 - 0x40);
                        *(rcx_19 - 0x30) = zmm1;
                        zmm0 = *(rdx + rcx_19 - 0x20);
                        zmm1 = *(rdx + rcx_19 - 0x10);
                        
                        if (temp3_1 == 1)
                            break;
                        
                        *(rcx_19 - 0x20) = zmm0;
                        *(rcx_19 - 0x10) = zmm1;
                    }
                }
                else
                {
                    while (true)
                    {
                        zmm0 = *(rdx + rcx_19);
                        zmm1 = *(rdx + rcx_19 + 0x10);
                        rcx_19 += 0x80;
                        *(rcx_19 - 0x80) = zmm0;
                        *(rcx_19 - 0x70) = zmm1;
                        zmm1 = *(rdx + rcx_19 - 0x50);
                        uint64_t temp5_1 = r9_7;
                        r9_7 -= 1;
                        *(rcx_19 - 0x60) = *(rdx + rcx_19 - 0x60);
                        *(rcx_19 - 0x50) = zmm1;
                        zmm1 = *(rdx + rcx_19 - 0x30);
                        *(rcx_19 - 0x40) = *(rdx + rcx_19 - 0x40);
                        *(rcx_19 - 0x30) = zmm1;
                        zmm0 = *(rdx + rcx_19 - 0x20);
                        zmm1 = *(rdx + rcx_19 - 0x10);
                        
                        if (temp5_1 == 1)
                            break;
                        
                        *(rcx_19 - 0x20) = zmm0;
                        *(rcx_19 - 0x10) = zmm1;
                    }
                }
                
                *(rcx_19 - 0x20) = zmm0;
                __saved_rsi_13 &= 0x7f;
                zmm0 = zmm1;
            }
        }
        
        uint64_t i_2 = __saved_rsi_13 >> 4;
        
        if (i_2)
        {
            uint64_t i_1;
            
            do
            {
                *(rcx_19 - 0x10) = zmm0;
                zmm0 = *(rdx + rcx_19);
                rcx_19 += 0x10;
                i_1 = i_2;
                i_2 -= 1;
            } while (i_1 != 1);
        }
        
        void* __saved_rsi_14 = __saved_rsi_13 & 0xf;
        
        if (__saved_rsi_14)
        {
            void* rax_6 = __saved_rsi_14 + rcx_19;
            *(rax_6 - 0x10) = *(rdx + rax_6 - 0x10);
        }
        
        *(rcx_19 - 0x10) = zmm0;
        return arg1;
    }
    
    switch (__saved_rsi)
    {
        case nullptr:
        {
            return arg1;
            break;
        }
        case 1:
        {
            *arg1 = *arg2;
            return arg1;
            break;
        }
        case 2:
        {
            *arg1 = *arg2;
            return arg1;
            break;
        }
        case 3:
        {
            char __saved_rsi_1 = *(arg2 + 2);
            *arg1 = *arg2;
            *(arg1 + 2) = __saved_rsi_1;
            return arg1;
            break;
        }
        case 4:
        {
            *arg1 = *arg2;
            return arg1;
            break;
        }
        case 5:
        {
            char __saved_rsi_3 = *(arg2 + 4);
            *arg1 = *arg2;
            *(arg1 + 4) = __saved_rsi_3;
            return arg1;
            break;
        }
        case 6:
        {
            int16_t __saved_rsi_4 = *(arg2 + 4);
            *arg1 = *arg2;
            *(arg1 + 4) = __saved_rsi_4;
            return arg1;
            break;
        }
        case 7:
        {
            int16_t __saved_rsi_5 = *(arg2 + 4);
            char r9_2 = *(arg2 + 6);
            *arg1 = *arg2;
            *(arg1 + 4) = __saved_rsi_5;
            *(arg1 + 6) = r9_2;
            return arg1;
            break;
        }
        case 8:
        {
            *arg1 = *arg2;
            return arg1;
            break;
        }
        case 9:
        {
            char rcx_14 = *(arg2 + 8);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_14;
            return arg1;
            break;
        }
        case 0xa:
        {
            int16_t rcx_15 = *(arg2 + 8);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_15;
            return arg1;
            break;
        }
        case 0xb:
        {
            int16_t rcx_7 = *(arg2 + 8);
            char r9_1 = *(arg2 + 0xa);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_7;
            *(arg1 + 0xa) = r9_1;
            return arg1;
            break;
        }
        case 0xc:
        {
            int32_t rcx_16 = *(arg2 + 8);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_16;
            return arg1;
            break;
        }
        case 0xd:
        {
            int32_t rcx_13 = *(arg2 + 8);
            char r9_3 = *(arg2 + 0xc);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_13;
            *(arg1 + 0xc) = r9_3;
            return arg1;
            break;
        }
        case 0xe:
        {
            int32_t rcx_17 = *(arg2 + 8);
            int16_t r9_4 = *(arg2 + 0xc);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_17;
            *(arg1 + 0xc) = r9_4;
            return arg1;
            break;
        }
        case 0xf:
        {
            int32_t rcx_18 = *(arg2 + 8);
            int16_t r9_5 = *(arg2 + 0xc);
            char r10_1 = *(arg2 + 0xe);
            *arg1 = *arg2;
            *(arg1 + 8) = rcx_18;
            *(arg1 + 0xc) = r9_5;
            *(arg1 + 0xe) = r10_1;
            return arg1;
            break;
        }
        case 0x10:
        {
            *arg1 = *arg2;
            return arg1;
            break;
        }
    }
}

int64_t* memset(void* arg1, char __saved_rdi, void* arg3)
{
    int64_t* result = arg1;
    uint64_t __saved_rdi_1 = __saved_rdi;
    int64_t r9 = 0x101010101010101 * __saved_rdi_1;
    
    if (arg3 > 0x10)
    {
        uint128_t zmm0 = r9;
        zmm0 = _mm_unpacklo_epi8(zmm0, zmm0);
        
        if (arg3 > 0x80)
        {
            if (TEST_BITD(data_140016f64, 1))
            {
                int64_t rcx_1;
                int64_t rdi_1;
                rdi_1 = __memfill_u8(arg1, __saved_rdi_1, arg3);
                return result;
            }
            
            *arg1 = zmm0;
            void* r8 = arg3 + arg1;
            arg1 = (arg1 + 0x10) & 0xfffffffffffffff0;
            arg3 = r8 - arg1;
            uint64_t i_2 = arg3 >> 7;
            
            if (i_2)
            {
                uint64_t i;
                
                do
                {
                    *arg1 = zmm0;
                    *(arg1 + 0x10) = zmm0;
                    arg1 += 0x80;
                    *(arg1 - 0x60) = zmm0;
                    *(arg1 - 0x50) = zmm0;
                    i = i_2;
                    i_2 -= 1;
                    *(arg1 - 0x40) = zmm0;
                    *(arg1 - 0x30) = zmm0;
                    *(arg1 - 0x20) = zmm0;
                    *(arg1 - 0x10) = zmm0;
                } while (i != 1);
                arg3 &= 0x7f;
            }
        }
        
        uint64_t i_3 = arg3 >> 4;
        
        if (i_3)
        {
            uint64_t i_1;
            
            do
            {
                *arg1 = zmm0;
                arg1 += 0x10;
                i_1 = i_3;
                i_3 -= 1;
            } while (i_1 != 1);
        }
        
        void* r8_1 = arg3 & 0xf;
        
        if (r8_1)
            *(r8_1 + arg1 - 0x10) = zmm0;
        
        return result;
    }
    
    void* rcx_3 = arg1 + arg3;
    
    switch (arg3)
    {
        case nullptr:
        {
            return result;
            break;
        }
        case 1:
        {
            *(rcx_3 - 1) = r9;
            return result;
            break;
        }
        case 2:
        {
            *(rcx_3 - 2) = r9;
            return result;
            break;
        }
        case 3:
        {
            goto label_140002c07;
        }
        case 4:
        {
            *(rcx_3 - 4) = r9;
            return result;
            break;
        }
        case 5:
        {
            goto label_140002c24;
        }
        case 6:
        {
            goto label_140002c34;
        }
        case 7:
        {
            goto label_140002c04;
        }
        case 8:
        {
            *result = r9;
            return result;
            break;
        }
        case 9:
        {
            *(rcx_3 - 9) = r9;
            *(rcx_3 - 1) = r9;
            return result;
            break;
        }
        case 0xa:
        {
            *result = r9;
            result[1] = r9;
            return result;
            break;
        }
        case 0xb:
        {
            *result = r9;
            result[1] = r9;
            *(result + 0xa) = r9;
            return result;
            break;
        }
        case 0xc:
        {
            *(rcx_3 - 0xc) = r9;
            *(rcx_3 - 4) = r9;
            return result;
            break;
        }
        case 0xd:
        {
            *(rcx_3 - 0xd) = r9;
            label_140002c24:
            *(rcx_3 - 5) = r9;
            *(rcx_3 - 1) = r9;
            return result;
            break;
        }
        case 0xe:
        {
            *(rcx_3 - 0xe) = r9;
            label_140002c34:
            *(rcx_3 - 6) = r9;
            *(rcx_3 - 2) = r9;
            return result;
            break;
        }
        case 0xf:
        {
            *(rcx_3 - 0xf) = r9;
            label_140002c04:
            *(rcx_3 - 7) = r9;
            label_140002c07:
            *(rcx_3 - 3) = r9;
            *(rcx_3 - 1) = r9;
            return result;
            break;
        }
        case 0x10:
        {
            *result = r9;
            result[1] = r9;
            return result;
            break;
        }
    }
}

int64_t __C_specific_handler(int32_t* arg1, int64_t arg2, void (* arg3)(), int64_t* arg4)
{
    int64_t r12 = arg4[1];
    int32_t* rbx = arg4[7];
    int64_t r15_1 = *arg4 - r12;
    
    if (arg1[1] & 0x66)
    {
        int32_t rdi_3 = arg4[9];
        int64_t rsi_1 = arg4[4] - r12;
        
        while (true)
        {
            int32_t rdx_5 = *rbx;
            
            if (rdi_3 >= rdx_5)
                break;
            
            uint64_t rcx_7 = rdi_3 * 2;
            
            if (r15_1 >= rbx[rcx_7 * 2 + 1] && r15_1 < rbx[rcx_7 * 2 + 2])
            {
                int32_t r10_2 = arg1[1] & 0x20;
                
                if (r10_2)
                {
                    int32_t r9_1 = 0;
                    
                    if (rdx_5)
                    {
                        do
                        {
                            uint64_t r8_3 = r9_1 * 2;
                            
                            if (rsi_1 >= rbx[r8_3 * 2 + 1] && rsi_1 < rbx[r8_3 * 2 + 2]
                                    && rbx[r8_3 * 2 + 4] == rbx[rcx_7 * 2 + 4]
                                    && rbx[r8_3 * 2 + 3] == rbx[rcx_7 * 2 + 3])
                                break;
                            
                            r9_1 += 1;
                        } while (r9_1 < rdx_5);
                    }
                    
                    if (r9_1 != rdx_5)
                        break;
                }
                
                uint64_t rax_16 = rbx[rcx_7 * 2 + 4];
                
                if (!rax_16)
                {
                    arg4[9] = rdi_3 + 1;
                    uint64_t r8_4 = rbx[rcx_7 * 2 + 3];
                    rcx_7 = 1;
                    (r8_4 + r12)(rcx_7, arg2);
                }
                else if (rsi_1 == rax_16 && r10_2)
                    break;
            }
            
            rdi_3 += 1;
        }
    }
    else
    {
        int32_t i = arg4[9];
        int32_t* var_38 = arg1;
        void (* var_30_1)() = arg3;
        
        for (; i < *rbx; i += 1)
        {
            uint64_t rdi_2 = i * 2;
            
            if (r15_1 >= rbx[rdi_2 * 2 + 1] && r15_1 < rbx[rdi_2 * 2 + 2] && rbx[rdi_2 * 2 + 4])
            {
                if (rbx[rdi_2 * 2 + 3] == 1)
                {
                    label_140002d17:
                    
                    if (*arg1 == 0xe06d7363 && data_140017c60
                            && _IsNonwritableInCurrentImage(&data_140017c60))
                        data_140017c60(arg1, 1);
                    
                    rbx[rdi_2 * 2 + 4];
                    _NLG_Notify();
                    RtlUnwindEx(arg2, rbx[rdi_2 * 2 + 4] + r12, arg1, *arg1, arg4[5], arg4[8]);
                }
                else
                {
                    int32_t rax_5 = (rbx[rdi_2 * 2 + 3] + r12)(&var_38, arg2);
                    
                    if (rax_5 < 0)
                        return 0;
                    
                    if (rax_5 > 0)
                        goto label_140002d17;
                }
            }
        }
    }
    
    return 1;
}

int64_t __vcrt_initialize()
{
    sub_140003594();
    sub_140003508();
    
    if (__vcrt_initialize_locks())
    {
        if (sub_1400030d4())
            return 1;
        
        __vcrt_uninitialize_locks();
    }
    
    return 0;
}

int64_t __vcrt_uninitialize(char arg1)
{
    if (!arg1)
    {
        __vcrt_uninitialize_ptd();
        __vcrt_uninitialize_locks();
        __vcrt_uninitialize_winapi_thunks(0);
    }
    
    int64_t result;
    result = 1;
    return result;
}

int64_t __std_exception_copy(int64_t* arg1, int64_t* arg2)
{
    if (arg1[1])
    {
        char* rax_1 = *arg1;
        
        if (rax_1)
        {
            int64_t rdi_1 = -1;
            
            do
                rdi_1 += 1;
             while (rax_1[rdi_1]);
            
            char* rax_2 = j_sub_140004aa0(rdi_1 + 1);
            char* rbx_1 = rax_2;
            
            if (rax_2)
            {
                sub_140004b00(rax_2, rdi_1 + 1, *arg1);
                arg2[1] = 1;
                *arg2 = rbx_1;
                rbx_1 = nullptr;
            }
            
            return sub_1400043fc(rbx_1);
        }
    }
    
    int64_t result = *arg1;
    *arg2 = result;
    arg2[1] = 0;
    return result;
}

void __std_exception_destroy(int64_t* arg1)
{
    if (arg1[1])
        sub_1400043fc(*arg1);
    
    arg1[1] = 0;
    *arg1 = 0;
}

void _CxxThrowException(void* pExceptionObject, void* pThrowInfo) __noreturn
{
    void* PcValue = pThrowInfo;
    int64_t var_58 = data_14000c750;
    int96_t var_48 = data_14000c760;
    int128_t zmm1 = data_14000c780;
    int128_t arguments = data_14000c770;
    int128_t var_28 = zmm1;
    
    if (pThrowInfo && *pThrowInfo & 0x10)
    {
        void* rdi_1 = *pExceptionObject;
        void* rax_1 = *(rdi_1 - 8);
        void (* rbx_1)() = *(rax_1 + 0x40);
        PcValue = *(rax_1 + 0x30);
        j__guard_check_icall(rbx_1);
        rbx_1(rdi_1 - 8);
    }
    
    *arguments[8] = pExceptionObject;
    var_28 = PcValue;
    int64_t BaseOfImage;
    int64_t BaseOfImage_1 = RtlPcToFileHeader(PcValue, &BaseOfImage);
    BaseOfImage = BaseOfImage_1;
    *var_28[8] = BaseOfImage_1;
    
    if (PcValue)
    {
        if (!(*PcValue & 8))
        {
            int32_t rax_2 = arguments;
            
            if (!BaseOfImage_1)
                rax_2 = 0x1994000;
            
            arguments = rax_2;
        }
        else
            arguments = 0x1994000;
    }
    
    RaiseException(var_58, *var_58[4], *var_48[8], &arguments);
    /* no return */
}

int64_t _local_unwind(int64_t arg1, int64_t arg2)
{
    CONTEXT var_4d8;
    var_4d8.P5Home = &var_4d8;
    var_4d8.P6Home = 0;
    return RtlUnwindEx(arg1, arg2, nullptr, nullptr, var_4d8.P5Home, var_4d8.P6Home);
}

int64_t _NLG_Notify()
{
    int64_t rcx;
    int64_t arg_8 = rcx;
    int64_t rdx;
    int64_t arg_18 = rdx;
    int32_t r8;
    int32_t arg_10 = r8;
    /* tailcall */
    return sub_1400030a0();
}

int64_t sub_1400030a0() __pure
{
    return;
}

int64_t sub_1400030b0() __pure
{
    return;
}

void __vcrt_freefls(int64_t arg1)
{
    if (arg1 && arg1 != &data_140016f70)
        _free_base(arg1);
}

uint32_t sub_1400030d4()
{
    uint32_t result = __vcrt_FlsAlloc(__vcrt_freefls);
    data_140016030 = result;
    
    if (result != 0xffffffff)
    {
        if (__vcrt_FlsSetValue(result, &data_140016f70))
            result = 1;
        else
        {
            __vcrt_uninitialize_ptd();
            result = 0;
        }
    }
    else
        result = 0;
    
    return result;
}

int64_t __vcrt_uninitialize_ptd()
{
    uint32_t rcx = data_140016030;
    
    if (rcx != 0xffffffff)
    {
        __vcrt_FlsFree(rcx);
        data_140016030 = 0xffffffff;
    }
    
    int64_t result;
    result = 1;
    return result;
}

int64_t __vcrt_initialize_locks()
{
    uint64_t rbx = 0;
    int32_t result;
    
    while (true)
    {
        if (!sub_140003490(&data_140016fe8 + rbx * 0x28, 0xfa0, 0))
        {
            __vcrt_uninitialize_locks();
            result = 0;
            break;
        }
        
        data_140017010 += 1;
        rbx = rbx + 1;
        
        if (rbx >= 1)
        {
            result = 1;
            break;
        }
    }
    
    return result;
}

int64_t __vcrt_uninitialize_locks()
{
    uint64_t rbx = data_140017010;
    
    while (rbx)
    {
        rbx = rbx - 1;
        DeleteCriticalSection(&data_140016fe8 + rbx * 0x28);
        data_140017010 -= 1;
    }
    
    int64_t result;
    result = 1;
    return result;
}

int64_t try_get_function(int32_t arg1, PSTR arg2, int32_t* arg3, int64_t arg4)
{
    uint64_t r14 = arg1;
    int64_t rax = 0;
    int32_t* rbp = arg3;
    
    if (0 == *((r14 << 3) + &data_140017040))
        *((r14 << 3) + &data_140017040) = 0;
    else
        rax = *((r14 << 3) + &data_140017040);
    
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t rdx_2 = RORQ(__security_cookie_1 ^ rax, __security_cookie_1 & 0x3f);
    
    if (rdx_2 != -1)
    {
        if (rdx_2)
            return rdx_2;
        
        HMODULE rbx_1;
        
        if (rbp == arg4)
        {
            label_1400032ed:
            rbx_1 = nullptr;
        }
        else
        {
            while (true)
            {
                uint64_t rsi_1 = *rbp;
                HMODULE rax_2 = nullptr;
                bool z_1;
                
                if (0 == *((rsi_1 << 3) + &data_140017020))
                {
                    *((rsi_1 << 3) + &data_140017020) = 0;
                    z_1 = true;
                }
                else
                {
                    rax_2 = *((rsi_1 << 3) + &data_140017020);
                    z_1 = false;
                }
                
                rbx_1 = rax_2;
                
                if (z_1)
                {
                    PWSTR lpLibFileName = (&data_14000c790)[rsi_1];
                    HMODULE rax_3 =
                        LoadLibraryExW(lpLibFileName, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
                    rbx_1 = rax_3;
                    
                    if (!rax_3)
                    {
                        if (GetLastError() != ERROR_INVALID_PARAMETER)
                            rbx_1 = nullptr;
                        else
                            rbx_1 = LoadLibraryExW(lpLibFileName, nullptr, 0);
                    }
                    
                    if (rbx_1)
                    {
                        int64_t temp0_2 = *((rsi_1 << 3) + &data_140017020);
                        *((rsi_1 << 3) + &data_140017020) = rbx_1;
                        
                        if (temp0_2)
                            FreeLibrary(rbx_1);
                        
                        goto label_1400032d4;
                    }
                    
                    *((rsi_1 << 3) + &data_140017020);
                    *((rsi_1 << 3) + &data_140017020) = -1;
                }
                else if (rax_2 != -1)
                {
                    label_1400032d4:
                    
                    if (rbx_1)
                    {
                        __security_cookie_1 = __security_cookie;
                        break;
                    }
                }
                
                rbp = &rbp[1];
                
                if (rbp == arg4)
                {
                    __security_cookie_1 = __security_cookie;
                    goto label_1400032ed;
                }
            }
        }
        
        if (rbx_1)
        {
            int64_t rax_1 = GetProcAddress(rbx_1, arg2);
            __security_cookie_1 = __security_cookie;
            
            if (rax_1)
            {
                *((r14 << 3) + &data_140017040);
                *((r14 << 3) + &data_140017040) =
                    RORQ(rax_1, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
                return rax_1;
            }
        }
        
        *((r14 << 3) + &data_140017040);
        *((r14 << 3) + &data_140017040) =
            RORQ(-1, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
    }
    
    return 0;
}

int64_t __vcrt_FlsAlloc(int64_t arg1)
{
    int64_t rax = try_get_function(4, "FlsAlloc", &data_14000c860, "FlsAlloc");
    
    if (!rax)
        return TlsAlloc();
    
    j__guard_check_icall(rax);
    return rax(arg1);
}

int64_t __vcrt_FlsFree(uint32_t arg1)
{
    int64_t rax = try_get_function(5, "FlsFree", &data_14000c878, "FlsFree");
    
    if (!rax)
        return TlsFree(arg1);
    
    j__guard_check_icall(rax);
    return rax(arg1);
}

int64_t __vcrt_FlsSetValue(uint32_t arg1, int64_t arg2)
{
    int64_t rax = try_get_function(7, "FlsSetValue", &data_14000c898, "FlsSetValue");
    
    if (!rax)
        return TlsSetValue(arg1, arg2);
    
    j__guard_check_icall(rax);
    return rax(arg1, arg2);
}

int64_t sub_140003490(CRITICAL_SECTION* arg1, uint32_t arg2, int32_t arg3)
{
    int64_t rax = try_get_function(8, "InitializeCriticalSectionEx", &data_14000c8b0, 
        "InitializeCriticalSectionEx");
    
    if (!rax)
        return InitializeCriticalSectionAndSpinCount(arg1, arg2);
    
    j__guard_check_icall(rax);
    return rax(arg1, arg2, arg3);
}

void* sub_140003508()
{
    int64_t i = 0;
    void* result = &data_140017040;
    int64_t __security_cookie_1 = __security_cookie;
    
    do
    {
        i += 1;
        *result = __security_cookie_1;
        result += 8;
    } while (i != (~(&data_140017088 - &data_140017088) & 9));
    
    return result;
}

void __vcrt_uninitialize_winapi_thunks(char arg1)
{
    if (!arg1)
    {
        for (void* i = &data_140017020; i != &data_140017040; i += 8)
        {
            HMODULE hLibModule = *i;
            
            if (hLibModule)
            {
                if (hLibModule != -1)
                    FreeLibrary(hLibModule);
                
                *i = 0;
            }
        }
    }
}

int64_t sub_140003594()
{
    int64_t __security_cookie_1 = __security_cookie;
    data_140017088 = __security_cookie_1;
    return __security_cookie_1;
}

uint64_t sub_1400035b8(int16_t* arg1, int64_t arg2, int64_t arg3)
{
    int32_t rbx = 0;
    int16_t* r9 = arg1;
    
    if (!arg1 || !arg2)
        goto label_1400035d5;
    
    if (arg3)
    {
        while (*arg1)
        {
            arg1 = &arg1[1];
            int64_t temp0_1 = arg2;
            arg2 -= 1;
            
            if (temp0_1 == 1)
                break;
        }
        
        if (!arg2)
        {
            *r9 = 0;
            goto label_1400035d5;
        }
        
        int16_t* r8 = arg3 - arg1;
        int64_t i;
        
        do
        {
            int16_t rax_3 = *(r8 + arg1);
            *arg1 = rax_3;
            arg1 = &arg1[1];
            
            if (!rax_3)
                break;
            
            i = arg2;
            arg2 -= 1;
        } while (i != 1);
        
        if (!arg2)
        {
            *r9 = 0;
            rbx = 0x22;
            *_errno() = rbx;
            _invalid_parameter_noinfo();
        }
    }
    else
    {
        *arg1 = 0;
        label_1400035d5:
        rbx = 0x16;
        *_errno() = rbx;
        _invalid_parameter_noinfo();
    }
    
    return rbx;
}

uint64_t _XcptFilter(int32_t arg1, int64_t arg2)
{
    void** rax = __acrt_getptd_noexit();
    
    if (rax)
    {
        void* rcx = *rax;
        void* rax_1 = rcx;
        
        if (rcx == rcx + 0xc0)
        {
            label_140003687:
            rax_1 = nullptr;
        }
        else
        {
            while (*rax_1 != arg1)
            {
                rax_1 += 0x10;
                
                if (rax_1 == rcx + 0xc0)
                    goto label_140003687;
            }
        }
        
        if (rax_1)
        {
            int64_t r8_1 = *(rax_1 + 8);
            
            if (r8_1)
            {
                if (r8_1 == 5)
                {
                    *(rax_1 + 8) = 0;
                    return r8_1 - 4;
                }
                
                if (r8_1 != 1)
                {
                    int64_t rbp_1 = rax[1];
                    rax[1] = arg2;
                    
                    if (*(rax_1 + 4) != 8)
                    {
                        uint64_t rcx_1 = *(rax_1 + 4);
                        *(rax_1 + 8) = 0;
                        r8_1(rcx_1);
                    }
                    else
                    {
                        void* i = rcx + 0x30;
                        
                        for (void* rdx_1 = i + 0x90; i != rdx_1; i += 0x10)
                            *(i + 8) = 0;
                        
                        int32_t rdi_1 = rax[2];
                        
                        if (*rax_1 == 0xc000008d)
                            rax[2] = 0x82;
                        else if (*rax_1 == 0xc000008e)
                            rax[2] = 0x83;
                        else if (*rax_1 == 0xc000008f)
                            rax[2] = 0x86;
                        else if (*rax_1 == 0xc0000090)
                            rax[2] = 0x81;
                        else if (*rax_1 == 0xc0000091)
                            rax[2] = 0x84;
                        else if (*rax_1 == 0xc0000092)
                            rax[2] = 0x8a;
                        else if (*rax_1 == 0xc0000093)
                            rax[2] = 0x85;
                        else if (*rax_1 == 0xc00002b4)
                            rax[2] = 0x8e;
                        else if (*rax_1 == 0xc00002b5)
                            rax[2] = 0x8d;
                        
                        r8_1(8, rax[2]);
                        rax[2] = rdi_1;
                    }
                    
                    rax[1] = rbp_1;
                }
                
                return 0xffffffff;
            }
        }
    }
    
    return 0;
}

uint64_t sub_1400037c4()
{
    return data_140017100;
}

int64_t sub_1400037cc(int32_t arg1)
{
    data_140017100 = arg1;
}

int64_t __acrt_has_user_matherr()
{
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t result;
    result = RORQ(__security_cookie_1 ^ data_140017108, __security_cookie_1 & 0x3f);
    return result;
}

int64_t sub_1400037f4(int64_t arg1)
{
    data_140017108 = arg1;
}

int64_t __acrt_invoke_user_matherr(int64_t arg1)
{
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t rdx_1 = RORQ(__security_cookie_1 ^ data_140017108, __security_cookie_1 & 0x3f);
    
    if (rdx_1)
        /* tailcall */
        return rdx_1(arg1, rdx_1);
    
    return 0;
}

int64_t __setusermatherr(int64_t arg1)
{
    uint64_t __security_cookie_1 = __security_cookie;
    data_140017108 = RORQ(arg1, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
}

int16_t sub_140003854(int16_t* arg1, int64_t* arg2, int16_t* arg3, int64_t* arg4, int64_t* arg5)
{
    int64_t* rbx = arg4;
    *arg5 = 0;
    *arg4 = 1;
    
    if (arg2)
    {
        *arg2 = arg3;
        arg2 = &arg2[1];
    }
    
    arg4 = 0;
    int16_t result;
    
    while (true)
    {
        if (*arg1 != 0x22)
        {
            *arg5 += 1;
            
            if (arg3)
            {
                *arg3 = *arg1;
                arg3 = &arg3[1];
            }
            
            result = *arg1;
            arg1 = &arg1[1];
            
            if (!result)
            {
                arg1 -= 2;
                break;
            }
        }
        else
        {
            result = 0x22;
            arg4 = !arg4;
            arg1 = &arg1[1];
        }
        
        if (!arg4)
        {
            if (result != 0x20 && result != 9)
                continue;
            
            if (!arg3)
                break;
            
            arg3[-1] = 0;
            break;
        }
    }
    
    int64_t rdi;
    rdi = 0;
    
    while (*arg1)
    {
        while (*arg1 == 0x20 || *arg1 == 9)
            arg1 = &arg1[1];
        
        if (!*arg1)
            break;
        
        if (arg2)
        {
            *arg2 = arg3;
            arg2 = &arg2[1];
        }
        
        *rbx += 1;
        
        while (true)
        {
            int32_t r11_1 = 1;
            uint32_t i = 0;
            
            while (*arg1 == 0x5c)
            {
                arg1 = &arg1[1];
                i += 1;
            }
            
            if (*arg1 == 0x22)
            {
                if (!(1 & i))
                {
                    if (!rdi || arg1[1] != 0x22)
                    {
                        r11_1 = 0;
                        rdi = !rdi;
                    }
                    else
                        arg1 = &arg1[1];
                }
                
                i u>>= 1;
            }
            
            while (i)
            {
                i -= 1;
                
                if (arg3)
                {
                    *arg3 = 0x5c;
                    arg3 = &arg3[1];
                }
                
                *arg5 += 1;
            }
            
            result = *arg1;
            
            if (!result)
                break;
            
            if (!rdi)
            {
                if (result == 0x20)
                    break;
                
                if (result == 9)
                    break;
            }
            
            if (r11_1)
            {
                if (arg3)
                {
                    *arg3 = result;
                    arg3 = &arg3[1];
                }
                
                *arg5 += 1;
            }
            
            arg1 = &arg1[1];
        }
        
        if (arg3)
        {
            *arg3 = 0;
            arg3 = &arg3[1];
        }
        
        *arg5 += 1;
    }
    
    if (arg2)
        *arg2 = 0;
    
    *rbx += 1;
    return result;
}

int64_t __acrt_allocate_buffer_for_argv(int64_t arg1, int64_t arg2, int64_t arg3)
{
    if (arg1 < 0x1fffffffffffffff && arg2 < COMBINE(0, -1) / arg3)
    {
        int64_t r10_1 = arg1 << 3;
        int64_t r9_1 = arg2 * arg3;
        
        if (-1 - r10_1 > r9_1)
        {
            int64_t result = _calloc_base(r9_1 + r10_1, 1);
            _free_base(0);
            return result;
        }
    }
    
    return 0;
}

uint64_t _configure_wide_argv(int32_t arg1)
{
    int32_t rdi = 0;
    
    if (arg1)
    {
        if (arg1 - 1 <= 1)
        {
            GetModuleFileNameW(nullptr, &data_140017110, 0x104);
            int16_t* rsi_1 = data_1400173e0;
            data_1400173e8 = &data_140017110;
            
            if (!rsi_1 || !*rsi_1)
                rsi_1 = &data_140017110;
            
            int64_t arg_18 = 0;
            int64_t arg_20 = 0;
            sub_140003854(rsi_1, nullptr, nullptr, &arg_18, &arg_20);
            int64_t r15_1 = arg_18;
            int64_t* rax_3 = __acrt_allocate_buffer_for_argv(r15_1, arg_20, 2);
            
            if (rax_3)
            {
                sub_140003854(rsi_1, rax_3, &rax_3[r15_1], &arg_18, &arg_20);
                
                if (arg1 != 1)
                {
                    int64_t* arg_10 = nullptr;
                    int32_t rax_7 = j_common_expand_argv_wildcards<wchar_t>(rax_3, &arg_10);
                    
                    if (!rax_7)
                    {
                        int64_t* rdx_4 = arg_10;
                        int64_t rcx_7 = 0;
                        int64_t* rax_8 = rdx_4;
                        
                        if (*rdx_4)
                        {
                            do
                            {
                                rax_8 = &rax_8[1];
                                rcx_7 += 1;
                            } while (*rax_8);
                        }
                        
                        data_1400173c0 = rcx_7;
                        arg_10 = nullptr;
                        data_1400173d0 = rdx_4;
                        _free_base(0);
                        arg_10 = nullptr;
                        _free_base(rax_3);
                    }
                    else
                    {
                        _free_base(arg_10);
                        arg_10 = nullptr;
                        _free_base(rax_3);
                        rdi = rax_7;
                    }
                }
                else
                {
                    int32_t rax_6 = arg_18 - 1;
                    data_1400173d0 = rax_3;
                    data_1400173c0 = rax_6;
                    _free_base(nullptr);
                }
            }
            else
            {
                *_errno() = 0xc;
                _free_base(0);
                rdi = 0xc;
            }
        }
        else
        {
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            rdi = 0x16;
        }
    }
    
    return rdi;
}

uint64_t common_initialize_environment_nolock<wchar_t>()
{
    int32_t rdi = 0;
    
    if (data_140017328)
        return 0;
    
    int128_t* rax_1 = __dcrt_get_wide_environment_from_os();
    
    if (rax_1)
    {
        int16_t** rax_2 = sub_140003c3c(rax_1);
        
        if (rax_2)
        {
            data_140017330 = rax_2;
            data_140017328 = rax_2;
        }
        else
            rdi = -1;
        
        _free_base(0);
    }
    else
        rdi = -1;
    
    _free_base(rax_1);
    return rdi;
}

int16_t** sub_140003c3c(int16_t* arg1)
{
    int16_t** result = nullptr;
    int16_t* r14 = arg1;
    int64_t rdx = 0;
    
    while (true)
    {
        int16_t rax_2 = *arg1;
        
        if (!rax_2)
            break;
        
        if (rax_2 != 0x3d)
            rdx += 1;
        
        int64_t rax_1 = -1;
        
        do
            rax_1 += 1;
         while (arg1[rax_1]);
        
        arg1 = &arg1[rax_1 + 1];
    }
    
    int16_t** result_1 = _calloc_base(rdx + 1, 8);
    
    if (result_1)
    {
        int16_t** result_2 = result_1;
        
        while (true)
        {
            if (!*r14)
            {
                result = result_1;
                break;
            }
            
            int64_t rbp_1 = -1;
            
            do
                rbp_1 += 1;
             while (r14[rbp_1]);
            
            if (*r14 != 0x3d)
            {
                int16_t* rax_3 = _calloc_base(rbp_1 + 1, 2);
                
                if (!rax_3)
                {
                    free_environment<wchar_t>(result_1);
                    _free_base(0);
                    break;
                }
                
                if (wcscpy_s(rax_3, rbp_1 + 1, r14))
                {
                    _invoke_watson(nullptr, nullptr, nullptr, 0, 0);
                    /* no return */
                }
                
                *result_2 = rax_3;
                result_2 = &result_2[1];
                _free_base(0);
            }
            
            r14 = &r14[rbp_1 + 1];
        }
    }
    
    _free_base(0);
    return result;
}

void free_environment<wchar_t>(int64_t* arg1)
{
    if (arg1)
    {
        int64_t i = *arg1;
        int64_t* rdi_1 = arg1;
        
        for (; i; i = *rdi_1)
        {
            _free_base(i);
            rdi_1 = &rdi_1[1];
        }
        
        _free_base(arg1);
    }
}

void uninitialize_environment_internal<wchar_t>(int64_t* arg1)
{
    int64_t* rcx = *arg1;
    
    if (rcx != data_140017338)
        free_environment<wchar_t>(rcx);
}

void uninitialize_environment_internal<char>(int64_t* arg1)
{
    int64_t* rcx = *arg1;
    
    if (rcx != data_140017330)
        free_environment<wchar_t>(rcx);
}

int64_t sub_140003dbc()
{
    uninitialize_environment_internal<wchar_t>(&data_140017320);
    uninitialize_environment_internal<char>(&data_140017328);
    free_environment<wchar_t>(data_140017338);
    /* tailcall */
    return free_environment<wchar_t>(data_140017330);
}

uint64_t j_common_initialize_environment_nolock<wchar_t>()
{
    /* tailcall */
    return common_initialize_environment_nolock<wchar_t>();
}

void* common_wincmdln<wchar_t>()
{
    void* result_1 = data_1400173e0;
    void* result = &data_140017340;
    
    if (result_1)
        result = result_1;
    
    result_1 = 0;
    
    while (true)
    {
        if (*result <= 0x20)
        {
            if (!*result)
                return result;
            
            if (!result_1)
            {
                while (true)
                {
                    int16_t rax = *result;
                    
                    if (!rax)
                        break;
                    
                    if (rax > 0x20)
                        break;
                    
                    result += 2;
                }
                
                return result;
            }
        }
        
        if (*result == 0x22)
            result_1 = !result_1;
        
        result += 2;
    }
}

void sub_140003e4c(int64_t* arg1, int64_t arg2)
{
    int64_t* rbx = arg1;
    int64_t rsi = 0;
    uint64_t rdi_3 = (arg2 - arg1 + 7) >> 3;
    
    if (arg1 > arg2)
        rdi_3 = 0;
    
    if (rdi_3)
    {
        do
        {
            int64_t rax = *rbx;
            
            if (rax)
                rax();
            
            rbx = &rbx[1];
            rsi += 1;
        } while (rsi != rdi_3);
    }
}

int64_t sub_140003eb0(int64_t* arg1, int64_t arg2)
{
    int64_t* rbx = arg1;
    
    for (bool cond:0 = arg1 == arg2; !cond:0; cond:0 = rbx == arg2)
    {
        int64_t rax_1 = *rbx;
        
        if (rax_1)
        {
            int32_t result = rax_1();
            
            if (result)
                return result;
        }
        
        rbx = &rbx[1];
    }
    
    return 0;
}

int64_t __crt_seh_guarded_call<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3>,void>::operator()<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    sub_140003f28(arg3);
    return __vcrt_lock(*arg4);
}

void sub_140003f28(int64_t* arg1)
{
    if (!data_140017350)
    {
        data_140017344 = 1;
        int32_t rcx = **arg1;
        
        if (!rcx)
        {
            uint64_t __security_cookie_1 = __security_cookie;
            int64_t rcx_1 = data_140017348;
            
            if (rcx_1 != __security_cookie_1)
                RORQ(__security_cookie_1 ^ rcx_1, __security_cookie_1 & 0x3f)(0, 0, 0);
            
            _execute_onexit_table(&data_140017368);
        }
        else if (rcx == 1)
            _execute_onexit_table(&data_140017380);
        
        if (!**arg1)
            sub_140003e4c(&data_14000c310, &data_14000c330);
        
        sub_140003e4c(&data_14000c338, &data_14000c340);
        
        if (!*arg1[1])
        {
            data_140017350 = 1;
            *arg1[2] = 1;
        }
    }
}

void sub_140003ff4() __noreturn
{
    sub_140004a40();
    /* no return */
}

int64_t dyntls_init_exception_filter(int32_t arg1) __pure
{
    int64_t result;
    result = arg1 == 0xe06d7363;
    return result;
}

int64_t common_exit(uint32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t arg_18 = arg3;
    int32_t arg_10 = arg2;
    
    if (!arg3)
    {
        HMODULE rax_1 = GetModuleHandleW(nullptr);
        
        if (rax_1 && rax_1->unused == 0x5a4d)
        {
            int32_t* rcx_1 = rax_1 * 2;
            
            if (*rcx_1 == 0x4550 && rcx_1[6] == 0x20b && rcx_1[0x21] > 0xe && rcx_1[0x3e])
                try_cor_exit_process(arg1);
        }
    }
    
    char arg_20 = 0;
    int32_t* var_28 = &arg_10;
    int32_t* var_20 = &arg_18;
    char* var_18 = &arg_20;
    int32_t var_34 = 2;
    int32_t var_30 = 2;
    void var_38;
    int64_t result = __crt_seh_guarded_call<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3>,void>::operator()<class <lambda_99476a1ad63dd22509b5d3e65b0ffc95>,class <lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c>& __ptr64,class <lambda_f7424dd8d45958661754dc4f2697e9c3> >(
        &var_38, &var_30, &var_28, &var_34);
    
    if (arg_18)
        return result;
    
    sub_1400040c8(arg1);
    /* no return */
}

void sub_1400040c8(uint32_t arg1) __noreturn
{
    TEB* gsbase;
    
    if (sub_1400068e4() != 1 && !(gsbase->ProcessEnvironmentBlock->NtGlobalFlag >> 8 & 1))
    {
        TerminateProcess(GetCurrentProcess(), arg1);
        /* no return */
    }
    
    try_cor_exit_process(arg1);
    ExitProcess(arg1);
    /* no return */
}

int64_t try_cor_exit_process(int32_t arg1)
{
    HMODULE hLibModule_1 = nullptr;
    int64_t result = GetModuleHandleExW(0, u"mscoree.dll", &hLibModule_1);
    
    if (result)
    {
        result = GetProcAddress(hLibModule_1, "CorExitProcess");
        
        if (result)
            result = result(arg1);
    }
    
    HMODULE hLibModule = hLibModule_1;
    
    if (!hLibModule)
        return result;
    
    return FreeLibrary(hLibModule);
}

int64_t sub_140004170(int64_t arg1)
{
    data_140017348 = arg1;
}

int64_t sub_140004178()
{
    /* tailcall */
    return common_exit(0, 2, 1);
}

int64_t _cexit()
{
    /* tailcall */
    return common_exit(0, 0, 1);
}

int64_t sub_140004198(uint32_t arg1)
{
    /* tailcall */
    return common_exit(arg1, 2, 0);
}

int64_t _register_thread_local_exe_atexit_callback(int64_t arg1)
{
    uint64_t __security_cookie_1 = __security_cookie;
    
    if (data_140017348 == __security_cookie_1)
    {
        data_140017348 = RORQ(arg1, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
        return __security_cookie_1;
    }
    
    sub_140004a40();
    /* no return */
}

int64_t sub_1400041e8(uint32_t arg1)
{
    /* tailcall */
    return common_exit(arg1, 0, 0);
}

int64_t _set_fmode(int32_t arg1)
{
    if ((arg1 - 0x4000) & 0xffff3fff || arg1 == 0xc000)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0x16;
    }
    
    data_140017624;
    data_140017624 = arg1;
    return 0;
}

int64_t __crt_seh_guarded_call<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a>,void>::operator()<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >(int64_t arg1, int32_t* arg2, int64_t arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int64_t* rbx = &data_140017a38;
    
    while (true)
    {
        int64_t* var_18_1 = rbx;
        
        if (rbx == &data_140017a40)
            break;
        
        if (*rbx != &data_140016590)
            *rbx = sub_140007750(rbx, &data_140016590);
        
        rbx = &rbx[1];
    }
    
    return __vcrt_lock(*arg4);
}

uint64_t Concurrency::details::WinRT::Initialize()
{
    int32_t temp0 = data_140017354;
    data_140017354 = 1;
    return temp0;
}

int64_t sub_1400042b0()
{
    int32_t arg_10 = 4;
    int32_t arg_18 = 4;
    void arg_8;
    return __crt_seh_guarded_call<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a>,void>::operator()<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >(
        &arg_8, &arg_18, &arg_8, &arg_10);
}

uint64_t _configthreadlocale(int32_t arg1)
{
    void** rax;
    int32_t rcx;
    rax = sub_14000538c();
    int32_t r8 = rax[0x75];
    
    if (arg1 == 0xffffffff)
        data_1400167a0 = 0xffffffff;
    else if (arg1)
    {
        int32_t r8_1;
        
        if (arg1 == 1)
            r8_1 = r8 | 2;
        else
        {
            if (arg1 != 2)
            {
                *_errno() = 0x16;
                _invalid_parameter_noinfo();
                return 0xffffffff;
            }
            
            r8_1 = r8 & 0xfffffffd;
        }
        
        rax[0x75] = r8_1;
    }
    
    return rcx - rcx + 2;
}

uint64_t sub_14000434c()
{
    return data_140017358;
}

uint64_t sub_140004354(int32_t arg1)
{
    if (arg1 > 1)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0xffffffff;
    }
    
    int32_t temp0_1 = data_140017358;
    data_140017358 = arg1;
    return temp0_1;
}

int64_t sub_140004380() __pure
{
    return &data_14001735c;
}

int64_t sub_140004388(int64_t arg1)
{
    data_140017360 = arg1;
}

int64_t sub_140004390(int64_t arg1)
{
    int64_t rax = sub_1400043c0();
    
    if (rax && rax(arg1))
        return 1;
    
    return 0;
}

int64_t sub_1400043c0()
{
    __vcrt_unlock(0);
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t result = RORQ(__security_cookie_1 ^ data_140017360, __security_cookie_1 & 0x3f);
    __vcrt_lock(0);
    return result;
}

int64_t j_sub_140004aa0(uint64_t arg1)
{
    /* tailcall */
    return sub_140004aa0(arg1);
}

int64_t sub_1400043fc(int64_t arg1)
{
    int32_t arg_10 = 0;
    /* tailcall */
    return _free_base(arg1);
}

uint64_t __crt_seh_guarded_call<class <lambda_8b90c8310d35b3462fe809c44bbb350d>,class <lambda_c1ccdfe150d00dafd355d15f2a9edeaa>& __ptr64,class <lambda_e797892004ba4c0bb152531b9d8c3715>,int32_t>::operator()<class <lambda_8b90c8310d35b3462fe809c44bbb350d>,class <lambda_c1ccdfe150d00dafd355d15f2a9edeaa>& __ptr64,class <lambda_e797892004ba4c0bb152531b9d8c3715> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int32_t rax = <lambda_4e60a939b0d047cfe11ddc22648dfba9>::operator()(arg3);
    __vcrt_lock(*arg4);
    return rax;
}

uint64_t __crt_seh_guarded_call<class <lambda_7777bce6b2f8c936911f934f8298dc43>,class <lambda_f03950bc5685219e0bcd2087efbe011e>& __ptr64,class <lambda_3883c3dff614d5e0c5f61bb1ac94921c>,int32_t>::operator()<class <lambda_7777bce6b2f8c936911f934f8298dc43>,class <lambda_f03950bc5685219e0bcd2087efbe011e>& __ptr64,class <lambda_3883c3dff614d5e0c5f61bb1ac94921c> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int32_t rax = <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()(arg3);
    __vcrt_lock(*arg4);
    return rax;
}

int64_t <lambda_4e60a939b0d047cfe11ddc22648dfba9>::operator()(int64_t* arg1)
{
    int64_t rsi = 0;
    int64_t* rbx = **arg1;
    
    if (rbx)
    {
        uint64_t __security_cookie_4 = __security_cookie;
        char rcx_1 = __security_cookie_4 & 0x3f;
        int64_t rbp_3 = RORQ(*rbx ^ __security_cookie_4, rcx_1);
        int64_t r9_3 = RORQ(rbx[1] ^ __security_cookie_4, rcx_1);
        int64_t rbx_3 = RORQ(rbx[2] ^ __security_cookie_4, rcx_1);
        
        if (r9_3 != rbx_3)
        {
            label_1400045dc:
            *r9_3 = RORQ(*arg1[1], 0x40 - (__security_cookie_4 & 0x3f)) ^ __security_cookie_4;
            uint64_t __security_cookie_1 = __security_cookie;
            ***arg1 = RORQ(rbp_3, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
            uint64_t __security_cookie_2 = __security_cookie;
            *(**arg1 + 8) =
                RORQ(r9_3 + 8, 0x40 - (__security_cookie_2 & 0x3f)) ^ __security_cookie_2;
            uint64_t __security_cookie_3 = __security_cookie;
            *(**arg1 + 0x10) =
                RORQ(rbx_3, 0x40 - (__security_cookie_3 & 0x3f)) ^ __security_cookie_3;
            return 0;
        }
        
        int64_t rbx_5 = (rbx_3 - rbp_3) >> 3;
        int64_t rdi_1 = rbx_5;
        
        if (rbx_5 > 0x200)
            rdi_1 = 0x200;
        
        int64_t rdi_2 = rdi_1 + rbx_5;
        
        if (rdi_1 == -(rbx_5))
            rdi_2 = 0x20;
        
        int64_t r14_1;
        
        if (rdi_2 >= rbx_5)
        {
            r14_1 = _recalloc_base(rbp_3, rdi_2, 8);
            _free_base(0);
        }
        
        if (rdi_2 >= rbx_5 && r14_1)
        {
            label_140004564:
            __security_cookie_4 = __security_cookie;
            r9_3 = r14_1 + (rbx_5 << 3);
            rbx_3 = r14_1 + (rdi_2 << 3);
            rbp_3 = r14_1;
            uint64_t rax_6 = (rbx_3 - r9_3 + 7) >> 3;
            int64_t rcx_4 = r9_3;
            
            if (r9_3 > rbx_3)
                rax_6 = 0;
            
            if (rax_6)
            {
                do
                {
                    rsi += 1;
                    *rcx_4 = __security_cookie_4;
                    rcx_4 += 8;
                } while (rsi != rax_6);
                
                __security_cookie_4 = __security_cookie;
            }
            
            goto label_1400045dc;
        }
        
        rdi_2 = rbx_5 + 4;
        r14_1 = _recalloc_base(rbp_3, rdi_2, 8);
        _free_base(0);
        
        if (r14_1)
            goto label_140004564;
    }
    
    return 0xffffffff;
}

int64_t <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()(int64_t* arg1)
{
    int64_t* rbx = **arg1;
    
    if (!rbx)
        return 0xffffffff;
    
    uint64_t __security_cookie_1 = __security_cookie;
    char r9_2 = __security_cookie_1 & 0x3f;
    int64_t rdi_3 = RORQ(*rbx ^ __security_cookie_1, r9_2);
    int64_t rbx_3 = RORQ(rbx[1] ^ __security_cookie_1, r9_2);
    
    if (rdi_3 - 1 <= -3)
    {
        int64_t r13_1 = rdi_3;
        int64_t r12_1 = rbx_3;
        int64_t __security_cookie_2 = __security_cookie_1;
        
        while (true)
        {
            rbx_3 -= 8;
            
            if (rbx_3 < rdi_3)
                break;
            
            if (*rbx_3 != __security_cookie_2)
            {
                int64_t rax_4 = *rbx_3 ^ __security_cookie_1;
                *rbx_3 = __security_cookie_2;
                RORQ(rax_4, r9_2)(r9_2);
                __security_cookie_1 = __security_cookie;
                r9_2 = __security_cookie_1 & 0x3f;
                int64_t* rdx_1 = **arg1;
                int64_t r10_3 = RORQ(*rdx_1 ^ __security_cookie_1, r9_2);
                int64_t rax_9 = RORQ(rdx_1[1] ^ __security_cookie_1, r9_2);
                
                if (r10_3 == r13_1 && rax_9 == r12_1)
                    continue;
                
                r13_1 = r10_3;
                rdi_3 = r10_3;
                r12_1 = rax_9;
                rbx_3 = rax_9;
            }
        }
        
        if (rdi_3 != -1)
        {
            _free_base(rdi_3);
            __security_cookie_1 = __security_cookie;
        }
        
        ***arg1 = __security_cookie_1;
        *(**arg1 + 8) = __security_cookie_1;
        *(**arg1 + 0x10) = __security_cookie_1;
    }
    
    return 0;
}

int64_t sub_1400047b0(int64_t arg1)
{
    /* tailcall */
    return sub_14000483c(&data_140017368, arg1);
}

uint64_t _execute_onexit_table(int64_t arg1)
{
    int64_t arg_8 = arg1;
    int64_t* var_18 = &arg_8;
    int32_t arg_18 = 2;
    int32_t arg_20 = 2;
    void arg_10;
    return __crt_seh_guarded_call<class <lambda_7777bce6b2f8c936911f934f8298dc43>,class <lambda_f03950bc5685219e0bcd2087efbe011e>& __ptr64,class <lambda_3883c3dff614d5e0c5f61bb1ac94921c>,int32_t>::operator()<class <lambda_7777bce6b2f8c936911f934f8298dc43>,class <lambda_f03950bc5685219e0bcd2087efbe011e>& __ptr64,class <lambda_3883c3dff614d5e0c5f61bb1ac94921c> >(
        &arg_10, &arg_20, &var_18, &arg_18);
}

int64_t sub_1400047fc(int64_t* arg1)
{
    int64_t* r8 = arg1;
    
    if (!arg1)
        return 0xffffffff;
    
    if (*arg1 == arg1[2])
    {
        int64_t __security_cookie_1 = __security_cookie;
        *r8 = __security_cookie_1;
        r8[1] = __security_cookie_1;
        r8[2] = __security_cookie_1;
    }
    
    return 0;
}

uint64_t sub_14000483c(int64_t arg1, int64_t arg2)
{
    int64_t arg_10 = arg2;
    int64_t arg_8 = arg1;
    int64_t* var_20 = &arg_8;
    int64_t* var_18 = &arg_10;
    int32_t arg_20 = 2;
    int32_t var_28 = 2;
    void arg_18;
    return __crt_seh_guarded_call<class <lambda_8b90c8310d35b3462fe809c44bbb350d>,class <lambda_c1ccdfe150d00dafd355d15f2a9edeaa>& __ptr64,class <lambda_e797892004ba4c0bb152531b9d8c3715>,int32_t>::operator()<class <lambda_8b90c8310d35b3462fe809c44bbb350d>,class <lambda_c1ccdfe150d00dafd355d15f2a9edeaa>& __ptr64,class <lambda_e797892004ba4c0bb152531b9d8c3715> >(
        &arg_18, &var_28, &var_20, &arg_20);
}

int64_t sub_140004884()
{
    data_140017a38 = &data_140016590;
    wchar16 const (** rax)[0x21];
    rax = 1;
    return &data_140016501;
}

int64_t sub_140004898()
{
    sub_1400047fc(&data_140017368);
    sub_1400047fc(&data_140017380);
    int64_t result;
    result = 1;
    return result;
}

int64_t __vcrt_uninitialize_critical()
{
    sub_140003dbc();
    int64_t result;
    result = 1;
    return result;
}

int64_t sub_1400048cc() __pure
{
    int64_t result;
    result = 1;
    return result;
}

uint64_t sub_1400048d0()
{
    uint64_t __security_cookie_1 = __security_cookie;
    sub_140004e1c(__security_cookie_1);
    sub_140004388(__security_cookie_1);
    _initp_misc_winsig(__security_cookie_1);
    sub_1400037f4(__security_cookie_1);
    sub_140004170(__security_cookie_1);
    uint64_t result;
    result = 1;
    return result;
}

int64_t j___vcrt_uninitialize()
{
    /* tailcall */
    return __vcrt_uninitialize(0);
}

int64_t sub_14000492c()
{
    __crt_state_management::dual_state_global<class <lambda_af42a3ee9806e9a7305d451646e05244>,struct __crt_multibyte_data* __ptr64>::uninitialize<class <lambda_af42a3ee9806e9a7305d451646e05244> >(
        &data_1400173a0);
    _free_base(data_140017c20);
    int64_t rcx_1 = data_140017c28;
    data_140017c20 = 0;
    _free_base(rcx_1);
    int64_t rcx_2 = data_1400173c8;
    data_140017c28 = 0;
    _free_base(rcx_2);
    int64_t rcx_3 = data_1400173d0;
    data_1400173c8 = 0;
    _free_base(rcx_3);
    data_1400173d0 = 0;
    int64_t result;
    result = 1;
    return result;
}

int32_t* __crt_state_management::dual_state_global<class <lambda_af42a3ee9806e9a7305d451646e05244>,struct __crt_multibyte_data* __ptr64>::uninitialize<class <lambda_af42a3ee9806e9a7305d451646e05244> >(int64_t* arg1)
{
    int64_t rdi = 0;
    int32_t* result = &arg1[1];
    int64_t* rbx = arg1;
    uint64_t rsi_3 = (result - arg1 + 7) >> 3;
    
    if (arg1 > result)
        rsi_3 = 0;
    
    if (rsi_3)
    {
        do
        {
            result = *rbx;
            int32_t rcx = *result;
            *result -= 1;
            
            if (rcx == 1 && *rbx != &data_140016050)
            {
                result = _free_base(*rbx);
                *rbx = &data_140016050;
            }
            
            rbx = &rbx[1];
            rdi += 1;
        } while (rdi != rsi_3);
    }
    
    return result;
}

int64_t sub_140004a18()
{
    /* tailcall */
    return __acrt_execute_initializers(&data_14000d360, &data_14000d450);
}

int64_t sub_140004a2c()
{
    /* tailcall */
    return sub_140007e58(&data_14000d360, &data_14000d450);
}

void sub_140004a40() __noreturn
{
    int64_t rax_1 = sub_14000538c()[3];
    
    if (rax_1)
        rax_1();
    
    abort();
    /* no return */
}

void _free_base(int64_t arg1)
{
    if (arg1 && !HeapFree(data_140017bf8, HEAP_NONE, arg1))
    {
        BOOL* rbx_1 = _errno();
        *rbx_1 = __acrt_errno_from_os_error(GetLastError());
    }
}

int64_t sub_140004aa0(uint64_t arg1)
{
    uint64_t dwBytes = arg1;
    
    if (arg1 <= -0x20)
    {
        if (!arg1)
            dwBytes = 1;
        
        int32_t i;
        
        do
        {
            int64_t result = HeapAlloc(data_140017bf8, HEAP_NONE, dwBytes);
            
            if (result)
                return result;
            
            if (!sub_14000434c())
                break;
            
            i = sub_140004390(dwBytes);
        } while (i);
    }
    
    *_errno() = 0xc;
    return 0;
}

uint64_t sub_140004b00(char* arg1, int64_t arg2, int64_t arg3)
{
    int32_t rbx = 0;
    
    if (!arg1 || !arg2)
        goto label_140004b19;
    
    if (arg3)
    {
        char* r9_1 = arg1;
        int64_t i;
        
        do
        {
            char rax = *(arg3 - arg1 + r9_1);
            *r9_1 = rax;
            r9_1 = &r9_1[1];
            
            if (!rax)
                break;
            
            i = arg2;
            arg2 -= 1;
        } while (i != 1);
        
        if (!arg2)
        {
            *arg1 = 0;
            rbx = 0x22;
            *_errno() = rbx;
            _invalid_parameter_noinfo();
        }
    }
    else
    {
        *arg1 = 0;
        label_140004b19:
        rbx = 0x16;
        *_errno() = rbx;
        _invalid_parameter_noinfo();
    }
    
    return rbx;
}

void abort() __noreturn
{
    if (__acrt_get_sigabrt_handler())
        raise(0x16);
    
    if (data_140016034 & 2)
    {
        if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
            trap(0xd);
        
        __acrt_call_reportfault(3, 0x40000015);
    }
    
    sub_140004198(3);
    breakpoint();
}

int64_t _calloc_base(int64_t arg1, int64_t arg2)
{
    if (!arg1 || COMBINE(0, -0x20) / arg1 >= arg2)
    {
        uint64_t dwBytes = arg1 * arg2;
        
        if (!dwBytes)
            dwBytes = 1;
        
        int32_t i;
        
        do
        {
            int64_t result = HeapAlloc(data_140017bf8, HEAP_ZERO_MEMORY, dwBytes);
            
            if (result)
                return result;
            
            if (!sub_14000434c())
                break;
            
            i = sub_140004390(dwBytes);
        } while (i);
    }
    
    *_errno() = 0xc;
    return 0;
}

int64_t* sub_140004c30(int64_t* arg1, int128_t* arg2)
{
    arg1[3] = 0;
    
    if (arg2)
        *(arg1 + 8) = *arg2;
    else if (data_140017354)
    {
        void** rax_1 = sub_14000538c();
        *arg1 = rax_1;
        arg1[1] = rax_1[0x12];
        arg1[2] = rax_1[0x11];
        __acrt_update_locale_info(rax_1, &arg1[1]);
        sub_140008348(*arg1, &arg1[2]);
        void* rcx_4 = *arg1;
        int32_t rax_2 = *(rcx_4 + 0x3a8);
        
        if (!(rax_2 & 2))
        {
            *(rcx_4 + 0x3a8) = rax_2 | 2;
            arg1[3] = 1;
        }
    }
    else
        *(arg1 + 8) = *data_1400166e8;
    
    return arg1;
}

int32_t __acrt_call_reportfault(int32_t arg1, int32_t arg2)
{
    void var_608;
    int64_t rax_1 = __security_cookie ^ &var_608;
    
    if (arg1 != 0xffffffff)
        sub_140001ff0();
    
    int32_t var_598;
    memset(&var_598, 0, 0x98);
    CONTEXT ContextRecord;
    memset(&ContextRecord, 0, 0x4d0);
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = &var_598;
    ExceptionInfo.ContextRecord = &ContextRecord;
    RtlCaptureContext(&ContextRecord);
    uint64_t Rip = ContextRecord.Rip;
    uint64_t ImageBase;
    IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
    uint64_t EstablisherFrame;
    void HandlerData;
    
    if (FunctionEntry)
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, ImageBase, Rip, FunctionEntry, &ContextRecord, 
            &HandlerData, &EstablisherFrame, nullptr);
    ContextRecord.Rip = __return_addr;
    var_598 = arg2;
    void arg_8;
    ContextRecord.Rsp = &arg_8;
    void* const __return_addr_1 = __return_addr;
    int32_t r8;
    int32_t var_594 = r8;
    BOOL rax_4 = IsDebuggerPresent();
    SetUnhandledExceptionFilter(nullptr);
    int32_t result = UnhandledExceptionFilter(&ExceptionInfo);
    
    if (!result && !rax_4 && arg1 != 0xffffffff)
        sub_140001ff0();
    
    __security_check_cookie(rax_1 ^ &var_608);
    return result;
}

int64_t sub_140004e1c(int64_t arg1)
{
    data_140017398 = arg1;
}

int64_t sub_140004e24(wchar16* arg1, wchar16* arg2, wchar16* arg3, uint32_t arg4, uint64_t arg5)
{
    void** rax = __acrt_getptd_noexit();
    int64_t rax_1;
    
    if (rax)
        rax_1 = rax[0x77];
    
    uint64_t var_18;
    wchar16* function_name;
    wchar16* file_name;
    uint32_t line_number;
    
    if (!rax || !rax_1)
    {
        uint64_t __security_cookie_1 = __security_cookie;
        line_number = arg4;
        file_name = arg3;
        int64_t r10_2 = RORQ(__security_cookie_1 ^ data_140017398, __security_cookie_1 & 0x3f);
        function_name = arg2;
        
        if (!r10_2)
        {
            _invoke_watson(arg1, function_name, file_name, line_number, arg5);
            /* no return */
        }
        
        rax_1 = r10_2;
        var_18 = arg5;
    }
    else
    {
        line_number = arg4;
        var_18 = arg5;
        file_name = arg3;
        function_name = arg2;
    }
    
    return rax_1(arg1, function_name, file_name, line_number, var_18);
}

int64_t _invalid_parameter_noinfo()
{
    return sub_140004e24(nullptr, nullptr, nullptr, 0, 0);
}

void _invoke_watson(wchar16 const* const expression, wchar16 const* const function_name, wchar16 const* const file_name, uint32_t const line_number, uint64_t const reserved) __noreturn
{
    if (IsProcessorFeaturePresent(0x17))
        trap(0xd);
    
    __acrt_call_reportfault(2, 0xc0000417);
    /* tailcall */
    return TerminateProcess(GetCurrentProcess(), 0xc0000417);
}

uint64_t __acrt_errno_from_os_error(int32_t arg1)
{
    uint64_t rax = 0;
    void* const rdx = &data_14000d450;
    
    do
    {
        if (arg1 == *rdx)
            return *((rax << 3) + 0x14000d454);
        
        rax = rax + 1;
        rdx += 8;
    } while (rax < 0x2c);
    
    if (arg1 - 0x13 <= 0x11)
        return 0xd;
    
    if (arg1 - 0xbc <= 0xe)
        return 8;
    
    return 0x16;
}

int64_t __acrt_errno_map_os_error(int32_t arg1)
{
    void** rax = __acrt_getptd_noexit();
    void* rax_1;
    
    if (rax)
        rax_1 = rax + 0x24;
    else
        rax_1 = &data_14001603c;
    
    *rax_1 = arg1;
    void** rax_2 = __acrt_getptd_noexit();
    void* rbx = &data_140016038;
    
    if (rax_2)
        rbx = &rax_2[4];
    
    int32_t result = __acrt_errno_from_os_error(arg1);
    *rbx = result;
    return result;
}

void* __doserrno()
{
    void** rax = __acrt_getptd_noexit();
    
    if (rax)
        return rax + 0x24;
    
    return &data_14001603c;
}

void* _errno()
{
    void** rax = __acrt_getptd_noexit();
    
    if (rax)
        return &rax[4];
    
    return &data_140016038;
}

int64_t sub_140005014(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int32_t* rax_1 = *(**arg3 + 0x88);
    *rax_1 += 1;
    return __vcrt_lock(*arg4);
}

int64_t __crt_seh_guarded_call<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707>,void>::operator()<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    sub_140005324(**arg3, nullptr);
    return __vcrt_lock(*arg4);
}

int64_t __crt_seh_guarded_call<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077>,void>::operator()<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    sub_140005324(**arg3, **arg3[1]);
    return __vcrt_lock(*arg4);
}

int64_t __crt_seh_guarded_call<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff>,void>::operator()<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int32_t* rcx_2 = *(**arg3 + 0x88);
    
    if (rcx_2)
    {
        int32_t rax_1 = *rcx_2;
        *rcx_2 -= 1;
        
        if (rax_1 == 1 && rcx_2 != &data_140016050)
            _free_base(rcx_2);
    }
    
    return __vcrt_lock(*arg4);
}

int64_t sub_14000513c(void** arg1)
{
    void** var_30 = arg1;
    int64_t* var_20 = &var_30;
    int32_t arg_18 = 5;
    int32_t arg_20 = 5;
    int64_t* var_18 = &var_30;
    int64_t* var_28;
    int64_t* var_10 = &var_28;
    int32_t var_38 = 4;
    int32_t var_34 = 4;
    var_28 = &data_140017a38;
    arg1[5] = 1;
    *var_30 = &data_14000d260;
    var_30[0x75] = 1;
    var_30[0x11] = &data_140016050;
    *(var_30 + 0xbc) = 0x43;
    *(var_30 + 0x1c2) = 0x43;
    var_30[0x74] = 0;
    void arg_10;
    sub_140005014(&arg_10, &arg_20, &var_20, &arg_18);
    return __crt_seh_guarded_call<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077>,void>::operator()<class <lambda_5e887d1dcbef67a5eb4283622ba103bf>,class <lambda_4466841279450cc726390878d4a41900>& __ptr64,class <lambda_341c25c0346d94847f1f3c463c57e077> >(
        &arg_10, &var_34, &var_18, &var_38);
}

void destroy_fls(int64_t* arg1)
{
    if (arg1)
    {
        sub_14000522c(arg1);
        _free_base(arg1);
    }
}

int64_t sub_14000522c(int64_t* arg1)
{
    int64_t* var_20 = arg1;
    int64_t* var_18 = &var_20;
    int32_t arg_18 = 5;
    int32_t arg_20 = 5;
    int64_t* var_10 = &var_20;
    int32_t var_28 = 4;
    int32_t var_24 = 4;
    int64_t rax = *arg1;
    
    if (rax != &data_14000d260)
    {
        _free_base(rax);
        arg1 = var_20;
    }
    
    _free_base(arg1[0xe]);
    _free_base(var_20[0xb]);
    _free_base(var_20[0xc]);
    _free_base(var_20[0xd]);
    _free_base(var_20[9]);
    _free_base(var_20[0xa]);
    _free_base(var_20[0xf]);
    _free_base(var_20[0x10]);
    _free_base(var_20[0x78]);
    void arg_10;
    __crt_seh_guarded_call<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff>,void>::operator()<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >(
        &arg_10, &arg_20, &var_18, &arg_18);
    return __crt_seh_guarded_call<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707>,void>::operator()<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707> >(
        &arg_10, &var_24, &var_10, &var_28);
}

void sub_140005324(void* arg1, void* arg2)
{
    void* rcx = *(arg1 + 0x90);
    
    if (rcx)
    {
        __acrt_release_locale_ref(rcx);
        void* rcx_1 = *(arg1 + 0x90);
        
        if (rcx_1 != data_140017a38 && rcx_1 != &data_140016590 && !*(rcx_1 + 0x10))
            __acrt_free_locale(rcx_1);
    }
    
    *(arg1 + 0x90) = arg2;
    
    if (arg2)
        sub_1400073ac(arg2);
}

void** sub_14000538c()
{
    enum WIN32_ERROR dwErrCode = GetLastError();
    uint32_t rcx = data_140016040;
    
    if (rcx == 0xffffffff)
        goto label_1400053cb;
    
    void** result_1 = sub_140007a70(rcx);
    void** result = result_1;
    
    if (!result_1)
    {
        rcx = data_140016040;
        label_1400053cb:
        
        if (sub_140007ab8(rcx, -1))
        {
            void** result_2 = _calloc_base(1, 0x3c8);
            uint32_t rcx_1 = data_140016040;
            result = result_2;
            
            if (result_2)
            {
                if (sub_140007ab8(rcx_1, result_2))
                {
                    sub_14000513c(result);
                    _free_base(0);
                    label_14000542e:
                    
                    if (result)
                    {
                        SetLastError(dwErrCode);
                        return result;
                    }
                }
                else
                {
                    sub_140007ab8(data_140016040, 0);
                    _free_base(result);
                }
            }
            else
            {
                sub_140007ab8(rcx_1, 0);
                _free_base(nullptr);
            }
        }
    }
    else if (result_1 != -1)
        goto label_14000542e;
    
    SetLastError(dwErrCode);
    abort();
    /* no return */
}

void** sub_140005458()
{
    uint32_t rcx = data_140016040;
    
    if (rcx == 0xffffffff)
        goto label_140005488;
    
    void** result_1 = sub_140007a70(rcx);
    void** result = result_1;
    
    if (!result_1)
    {
        rcx = data_140016040;
        label_140005488:
        
        if (sub_140007ab8(rcx, -1))
        {
            void** result_2 = _calloc_base(1, 0x3c8);
            uint32_t rcx_1 = data_140016040;
            result = result_2;
            
            if (result_2)
            {
                if (sub_140007ab8(rcx_1, result_2))
                {
                    sub_14000513c(result);
                    _free_base(0);
                    label_1400054eb:
                    
                    if (result)
                        return result;
                }
                else
                {
                    sub_140007ab8(data_140016040, 0);
                    _free_base(result);
                }
            }
            else
            {
                sub_140007ab8(rcx_1, 0);
                _free_base(nullptr);
            }
        }
    }
    else if (result_1 != -1)
        goto label_1400054eb;
    
    abort();
    /* no return */
}

void** __acrt_getptd_noexit()
{
    enum WIN32_ERROR dwErrCode = GetLastError();
    uint32_t rcx = data_140016040;
    
    if (rcx == 0xffffffff)
        goto label_140005556;
    
    void** result_1 = sub_140007a70(rcx);
    void** result = result_1;
    
    if (!result_1)
    {
        rcx = data_140016040;
        label_140005556:
        
        if (sub_140007ab8(rcx, -1))
        {
            void** result_2 = _calloc_base(1, 0x3c8);
            uint32_t rcx_2 = data_140016040;
            result = result_2;
            
            if (result_2)
            {
                if (sub_140007ab8(rcx_2, result_2))
                {
                    sub_14000513c(result);
                    _free_base(0);
                    label_1400055b9:
                    
                    if (result)
                    {
                        SetLastError(dwErrCode);
                        return result;
                    }
                }
                else
                {
                    sub_140007ab8(data_140016040, 0);
                    _free_base(result);
                }
            }
            else
            {
                sub_140007ab8(rcx_2, 0);
                _free_base(nullptr);
            }
        }
    }
    else if (result_1 != -1)
        goto label_1400055b9;
    
    SetLastError(dwErrCode);
    return nullptr;
}

void** __acrt_initialize_ptd()
{
    void** result = __acrt_FlsAlloc(destroy_fls);
    data_140016040 = result;
    
    if (result != 0xffffffff)
    {
        if (__acrt_getptd_noexit())
            result = 1;
        else
        {
            sub_14000560c();
            result = 0;
        }
    }
    else
        result = 0;
    
    return result;
}

int64_t sub_14000560c()
{
    uint32_t rcx = data_140016040;
    
    if (rcx != 0xffffffff)
    {
        __acrt_FlsFree(rcx);
        data_140016040 = 0xffffffff;
    }
    
    int64_t result;
    result = 1;
    return result;
}

uint64_t wcscpy_s(int16_t* arg1, int64_t arg2, int64_t arg3)
{
    int32_t rbx = 0;
    
    if (!arg1 || !arg2)
        goto label_14000564a;
    
    if (arg3)
    {
        int16_t* r9_1 = arg1;
        int64_t i;
        
        do
        {
            int16_t rax_3 = *(arg3 - arg1 + r9_1);
            *r9_1 = rax_3;
            r9_1 = &r9_1[1];
            
            if (!rax_3)
                break;
            
            i = arg2;
            arg2 -= 1;
        } while (i != 1);
        
        if (!arg2)
        {
            *arg1 = 0;
            rbx = 0x22;
            *_errno() = rbx;
            _invalid_parameter_noinfo();
        }
    }
    else
    {
        *arg1 = 0;
        label_14000564a:
        rbx = 0x16;
        *_errno() = rbx;
        _invalid_parameter_noinfo();
    }
    
    return rbx;
}

uint64_t sub_140005698(int16_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    int32_t r10 = 0;
    
    if (arg4)
    {
        if (!arg1 || !arg2)
            goto label_1400056b7;
        
        label_1400056e3:
        
        if (!arg4)
            *arg1 = 0;
        else
        {
            void* rax_1;
            int32_t rbx_1;
            
            if (arg3)
            {
                int16_t* r8 = arg3 - arg1;
                int16_t* rdx = arg1;
                int64_t i_2 = arg2;
                int64_t i_3 = arg4;
                
                if (arg4 != -1)
                {
                    int64_t i;
                    
                    do
                    {
                        int16_t rax_4 = *(r8 + rdx);
                        *rdx = rax_4;
                        rdx = &rdx[1];
                        
                        if (!rax_4)
                            break;
                        
                        int64_t i_4 = i_2;
                        i_2 -= 1;
                        
                        if (i_4 == 1)
                            break;
                        
                        i = i_3;
                        i_3 -= 1;
                    } while (i != 1);
                    
                    if (!i_3)
                        *rdx = 0;
                }
                else
                {
                    int64_t i_1;
                    
                    do
                    {
                        int16_t rax_3 = *(r8 + rdx);
                        *rdx = rax_3;
                        rdx = &rdx[1];
                        
                        if (!rax_3)
                            break;
                        
                        i_1 = i_2;
                        i_2 -= 1;
                    } while (i_1 != 1);
                }
                
                if (!i_2)
                {
                    if (arg4 != -1)
                    {
                        *arg1 = 0;
                        rax_1 = _errno();
                        rbx_1 = 0x22;
                        goto label_1400056c1;
                    }
                    
                    arg1[arg2 - 1] = 0;
                    r10 = i_2 + 0x50;
                }
            }
            else
            {
                *arg1 = 0;
                label_1400056b7:
                rax_1 = _errno();
                rbx_1 = 0x16;
                label_1400056c1:
                *rax_1 = rbx_1;
                _invalid_parameter_noinfo();
                r10 = rbx_1;
            }
        }
    }
    else
    {
        if (arg1)
        {
            if (!arg2)
                goto label_1400056b7;
            
            goto label_1400056e3;
        }
        
        if (arg2)
            goto label_1400056b7;
    }
    
    return r10;
}

int64_t <lambda_2feae5270eb4d0d5532525f423405775>::<helper_func_cdecl>(int64_t arg1, int64_t arg2) __pure
{
    if (arg1 < arg2)
        return 0xffffffff;
    
    int64_t result;
    result = arg1 > arg2;
    return result;
}

uint64_t common_expand_argv_wildcards<wchar_t>(int64_t* arg1, int64_t* arg2)
{
    int64_t r15;
    int64_t var_38 = r15;
    void var_b8;
    int64_t rax_1 = __security_cookie ^ &var_b8;
    int64_t rdi = 0;
    int64_t* rbx = arg1;
    uint64_t result;
    
    if (arg2)
    {
        *arg2 = 0;
        bool cond:0_1 = !*arg1;
        int128_t s;
        __builtin_memset(&s, 0, 0x18);
        int64_t* rsi_1;
        int64_t r12_1;
        int32_t result_1;
        
        while (true)
        {
            int64_t var_50;
            
            if (cond:0_1)
            {
                rsi_1 = s;
                int64_t r9_2 = 0;
                r12_1 = *s[8];
                int64_t* rdx_2 = rsi_1;
                var_50 = 0;
                void* rax_5 = r12_1 - rsi_1;
                int64_t r8_2 = 0;
                uint64_t rcx_3 = (rax_5 + 7) >> 3;
                
                if (rsi_1 > r12_1)
                    rcx_3 = 0;
                
                result_1 = -1;
                
                if (rcx_3)
                {
                    do
                    {
                        int64_t rax_6 = -1;
                        
                        do
                            rax_6 += 1;
                         while (*(*rdx_2 + (rax_6 << 1)));
                        
                        rdx_2 = &rdx_2[1];
                        r9_2 = r9_2 + 1 + rax_6;
                        r8_2 += 1;
                    } while (r8_2 != rcx_3);
                    
                    var_50 = r9_2;
                }
                
                int64_t rax_7 = __acrt_allocate_buffer_for_argv((rax_5 >> 3) + 1, r9_2, 2);
                
                if (rax_7)
                {
                    int16_t* rdx_4 = rax_7 + (((rax_5 >> 3) + 1) << 3);
                    int64_t* r15_4 = rsi_1;
                    int16_t* var_60_1 = rdx_4;
                    int16_t* rcx_5 = rdx_4;
                    int16_t* var_88_1 = rdx_4;
                    
                    if (rsi_1 != r12_1)
                    {
                        do
                        {
                            int64_t r8_3 = *r15_4;
                            int64_t r13_1 = -1;
                            
                            do
                                r13_1 += 1;
                             while (*(r8_3 + (r13_1 << 1)));
                            
                            if (sub_140005698(rcx_5, var_50 - ((rcx_5 - rdx_4) >> 1), r8_3, 
                                r13_1 + 1))
                            {
                                _invoke_watson(nullptr, nullptr, nullptr, 0, 0);
                                /* no return */
                            }
                            
                            rdx_4 = var_60_1;
                            *(rax_7 - rsi_1 + r15_4) = var_88_1;
                            r15_4 = &r15_4[1];
                            rcx_5 = &var_88_1[r13_1 + 1];
                            var_88_1 = rcx_5;
                        } while (r15_4 != r12_1);
                    }
                    
                    result_1 = 0;
                    *arg2 = rax_7;
                }
                
                _free_base(0);
                break;
            }
            
            var_50 = 0x3f002a;
            *var_50[4] = 0;
            int16_t* rax_3 = sub_1400071c0(*rbx, &var_50);
            PWSTR rcx_1 = *rbx;
            int32_t result_2;
            
            if (rax_3)
                result_2 = sub_140005b58(rcx_1, rax_3, &s, r15);
            else
                result_2 = sub_1400059c0(rcx_1, 0, 0, &s);
            
            result_1 = result_2;
            
            if (result_2)
            {
                r12_1 = *s[8];
                rsi_1 = s;
                break;
            }
            
            rbx = &rbx[1];
            cond:0_1 = !*rbx;
        }
        
        int64_t* r15_5 = rsi_1;
        uint64_t rbx_5 = (r12_1 - rsi_1 + 7) >> 3;
        
        if (rsi_1 > r12_1)
            rbx_5 = 0;
        
        if (rbx_5)
        {
            do
            {
                _free_base(*r15_5);
                rdi += 1;
                r15_5 = &r15_5[1];
            } while (rdi != rbx_5);
        }
        
        _free_base(rsi_1);
        result = result_1;
    }
    else
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        result = 0x16;
    }
    
    __security_check_cookie(rax_1 ^ &var_b8);
    return result;
}

uint64_t sub_1400059c0(int64_t arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    int64_t rbp = -1;
    int32_t rdi = 0;
    
    do
        rbp += 1;
     while (*(arg1 + (rbp << 1)));
    
    if (rbp + 1 > -1 - arg3)
        return 0xc;
    
    int64_t r15_2 = arg3 + 1 + rbp + 1;
    int16_t* rax_2 = _calloc_base(r15_2, 2);
    
    if (arg3 && sub_140005698(rax_2, r15_2, arg2, arg3))
    {
        _invoke_watson(nullptr, nullptr, nullptr, 0, 0);
        /* no return */
    }
    
    int32_t rax_4 = sub_140005698(&rax_2[arg3], r15_2 - arg3, arg1, rbp + 1);
    
    if (rax_4)
    {
        _invoke_watson(nullptr, nullptr, nullptr, 0, 0);
        /* no return */
    }
    
    int64_t r14_1 = arg4[2];
    uint64_t r15_4 = rax_4 + 8;
    
    if (arg4[1] != r14_1)
    {
        *arg4[1] = rax_2;
        arg4[1] += r15_4;
    }
    else if (*arg4)
    {
        int64_t r14_3 = (r14_1 - *arg4) >> 3;
        
        if (r14_3 > 0x7fffffffffffffff)
        {
            _free_base(rax_2);
            rdi = 0xc;
        }
        else
        {
            int64_t rbp_2 = r14_3 * 2;
            void* rax_8 = _recalloc_base(*arg4, rbp_2, r15_4);
            
            if (rax_8)
            {
                *arg4 = rax_8;
                arg4[1] = rax_8 + (r14_3 << 3);
                arg4[2] = rax_8 + (rbp_2 << 3);
                _free_base(0);
                *arg4[1] = rax_2;
                arg4[1] += r15_4;
            }
            else
            {
                _free_base(0);
                _free_base(rax_2);
                rdi = 0xc;
            }
        }
    }
    else
    {
        *arg4 = _calloc_base(rax_4 + 4, r15_4);
        _free_base(0);
        int64_t rax_6 = *arg4;
        
        if (!rax_6)
        {
            _free_base(rax_2);
            rdi = 0xc;
        }
        else
        {
            arg4[1] = rax_6;
            arg4[2] = rax_6 + 0x20;
            *arg4[1] = rax_2;
            arg4[1] += r15_4;
        }
    }
    
    _free_base(0);
    return rdi;
}

uint64_t sub_140005b58(PWSTR arg1, int16_t* arg2, int64_t* arg3, int64_t arg4 @ r15)
{
    int64_t var_28 = arg4;
    void var_2b8;
    int64_t rax_1 = __security_cookie ^ &var_2b8;
    
    for (; arg2 != arg1; arg2 -= 2)
    {
        int16_t rax_2 = *arg2 - 0x2f;
        
        if (rax_2 <= 0x2d && TEST_BITQ(0x200000000801, rax_2))
            break;
    }
    
    int16_t rcx = *arg2;
    uint64_t result;
    
    if (rcx != 0x3a || arg2 == &arg1[1])
    {
        int32_t result_1 = 0;
        uint64_t rax_5;
        char rax_6;
        
        if (rcx - 0x2f <= 0x2d)
        {
            rax_5 = rcx - 0x2f;
            rax_6 = 1;
        }
        
        if (rcx - 0x2f > 0x2d || !TEST_BITQ(0x200000000801, rax_5))
            rax_6 = 0;
        
        WIN32_FIND_DATAW findFileData;
        memset(&findFileData, 0, 0x250);
        HANDLE hFindFile =
            FindFirstFileExW(arg1, FindExInfoStandard, &findFileData, FindExSearchNameMatch, 0, 0);
        int32_t result_2;
        
        if (hFindFile != -1)
        {
            int64_t rsi_3 = (arg3[1] - *arg3) >> 3;
            BOOL i;
            
            do
            {
                if (findFileData.cFileName[0] != 0x2e)
                {
                    label_140005cb8:
                    var_25c;
                    result_2 = sub_1400059c0(&var_25c, arg1, 
                        (arg4 - arg4) & (((arg2 - arg1) >> 1) + 1), arg3);
                    
                    if (result_2)
                        goto label_140005c47;
                }
                else if (findFileData.cFileName[1]
                        && (findFileData.cFileName[1] != 0x2e || findFileData.cFileName[2]))
                    goto label_140005cb8;
                
                i = FindNextFileW(hFindFile, &findFileData);
            } while (i);
            int64_t rax_7 = *arg3;
            int64_t rdx_7 = (arg3[1] - rax_7) >> 3;
            
            if (rsi_3 != rdx_7)
                qsort(rax_7 + (rsi_3 << 3), rdx_7 - rsi_3, 8, 
                    <lambda_2feae5270eb4d0d5532525f423405775>::<helper_func_cdecl>);
        }
        else
        {
            result_2 = sub_1400059c0(arg1, 0, 0, arg3);
            label_140005c47:
            result_1 = result_2;
        }
        
        if (hFindFile != -1)
            FindClose(hFindFile);
        
        result = result_1;
    }
    else
        result = sub_1400059c0(arg1, 0, 0, arg3);
    
    __security_check_cookie(rax_1 ^ &var_2b8);
    return result;
}

uint64_t j_common_expand_argv_wildcards<wchar_t>(int64_t* arg1, int64_t* arg2)
{
    /* tailcall */
    return common_expand_argv_wildcards<wchar_t>(arg1, arg2);
}

int64_t sub_140005d10(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int128_t* rdx_1 = *(**arg3 + 0x88) + 0x18;
    int128_t* rcx_2 = data_1400173a8;
    int32_t rax_1;
    rax_1 = rcx_2;
    
    if (!rax_1)
        goto label_140005dc3;
    
    int64_t i_3;
    
    if (!rdx_1)
    {
        memset(rcx_2, rdx_1, 0x101);
        label_140005dc3:
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        i_3 = 2;
    }
    else
    {
        i_3 = 2;
        int64_t i_2 = 2;
        int64_t i;
        
        do
        {
            *rcx_2 = *rdx_1;
            rcx_2[1] = rdx_1[1];
            rcx_2[2] = rdx_1[2];
            rcx_2[3] = rdx_1[3];
            rcx_2[4] = rdx_1[4];
            rcx_2[5] = rdx_1[5];
            rcx_2[6] = rdx_1[6];
            rcx_2 = &rcx_2[8];
            rcx_2[-1] = rdx_1[7];
            rdx_1 = &rdx_1[8];
            i = i_2;
            i_2 -= 1;
        } while (i != 1);
        i_2 = *rdx_1;
        *rcx_2 = i_2;
    }
    
    int128_t* rdx_3 = *(**arg3 + 0x88) + 0x119;
    int128_t* rcx_4 = data_1400173b0;
    int32_t rax_4;
    rax_4 = rcx_4;
    
    if (!rax_4)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
    }
    else if (!rdx_3)
    {
        memset(rcx_4, rdx_3, 0x100);
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
    }
    else
    {
        int64_t i_1;
        
        do
        {
            *rcx_4 = *rdx_3;
            rcx_4[1] = rdx_3[1];
            rcx_4[2] = rdx_3[2];
            rcx_4[3] = rdx_3[3];
            rcx_4[4] = rdx_3[4];
            rcx_4[5] = rdx_3[5];
            rcx_4[6] = rdx_3[6];
            rcx_4 = &rcx_4[8];
            rcx_4[-1] = rdx_3[7];
            rdx_3 = &rdx_3[8];
            i_1 = i_3;
            i_3 -= 1;
        } while (i_1 != 1);
    }
    
    int32_t* rdx_4 = **arg3[1];
    int32_t rax_7 = *rdx_4;
    *rdx_4 -= 1;
    
    if (rax_7 == 1)
    {
        int64_t* rcx_6 = *arg3[1];
        
        if (*rcx_6 != &data_140016050)
            _free_base(*rcx_6);
    }
    
    **arg3[1] = *(**arg3 + 0x88);
    int32_t* rax_13 = *(**arg3 + 0x88);
    *rax_13 += 1;
    return __vcrt_lock(*arg4);
}

uint64_t sub_140005ed8(uint32_t arg1)
{
    uint32_t rbx = arg1;
    void* var_28;
    sub_140004c30(&var_28, nullptr);
    data_1400173b8 = 0;
    
    if (rbx == 0xfffffffe)
    {
        data_1400173b8 = 1;
        rbx = GetOEMCP();
    }
    else if (rbx == 0xfffffffd)
    {
        data_1400173b8 = 1;
        rbx = GetACP();
    }
    else if (rbx == 0xfffffffc)
    {
        data_1400173b8 = 1;
        void* var_20;
        rbx = *(var_20 + 0xc);
    }
    
    char var_10;
    
    if (var_10)
    {
        void* rcx_1 = var_28;
        *(rcx_1 + 0x3a8) &= 0xfffffffd;
    }
    
    return rbx;
}

int64_t sub_140005f58(void* arg1)
{
    char* rbx = arg1 + 0x18;
    int64_t i_3 = 0x101;
    memset(rbx, 0, 0x101);
    *(arg1 + 4) = 0;
    *(arg1 + 0x220) = 0;
    __builtin_memset(arg1 + 0xc, 0, 0xc);
    int64_t i;
    
    do
    {
        *rbx = *(&data_140016050 - arg1 + rbx);
        rbx = &rbx[1];
        i = i_3;
        i_3 -= 1;
    } while (i != 1);
    void* rcx_1 = arg1 + 0x119;
    int64_t i_2 = 0x100;
    char result;
    int64_t i_1;
    
    do
    {
        result = *(rcx_1 + &data_140016050 - arg1);
        *rcx_1 = result;
        rcx_1 += 1;
        i_1 = i_2;
        i_2 -= 1;
    } while (i_1 != 1);
    return result;
}

int64_t sub_140005fe8(void* arg1)
{
    void var_788;
    int64_t rax_1 = __security_cookie ^ &var_788;
    int64_t i_4 = 0x100;
    CPINFO cPInfo;
    int32_t result;
    
    if (!GetCPInfo(*(arg1 + 4), &cPInfo))
    {
        int32_t i = 0;
        void* rcx_4 = arg1 + 0x19;
        
        do
        {
            result = i - 0x41;
            
            if (result <= 0x19)
            {
                *rcx_4 |= 0x10;
                result = i + 0x20;
                *(rcx_4 + 0x100) = result;
            }
            else if (i - 0x61 > 0x19)
                *(rcx_4 + 0x100) = 0;
            else
            {
                *rcx_4 |= 0x20;
                result = i - 0x20;
                *(rcx_4 + 0x100) = result;
            }
            
            i += 1;
            rcx_4 += 1;
        } while (i < 0x100);
    }
    else
    {
        int32_t i_1 = 0;
        char var_718[0x90];
        char (* rcx_1)[0x90] = &var_718;
        
        do
        {
            *rcx_1 = i_1;
            i_1 += 1;
            rcx_1 = &(*rcx_1)[1];
        } while (i_1 < 0x100);
        
        i_1 = cPInfo.LeadByte[0];
        var_732;
        void* rdx_1 = &var_732;
        var_718[0] = 0x20;
        
        while (i_1)
        {
            uint32_t i_2 = *(rdx_1 + 1);
            uint64_t rcx_2 = i_1;
            
            while (rcx_2 <= i_2)
            {
                if (rcx_2 >= 0x100)
                    break;
                
                var_718[rcx_2] = 0x20;
                rcx_2 = rcx_2 + 1;
            }
            
            rdx_1 += 2;
            i_1 = *rdx_1;
        }
        
        uint16_t var_418[0x200];
        __acrt_GetStringTypeA(nullptr, 1, &var_718, 0x100, &var_418, *(arg1 + 4), 0);
        uint32_t var_760_1;
        void var_618;
        var_760_1 = &var_618;
        uint16_t* var_768_1;
        var_768_1 = 0x100;
        sub_140008c94(nullptr, *(arg1 + 0x220), 0x100, &var_718, var_768_1, var_760_1, 0x100, 
            *(arg1 + 4), 0);
        void var_518;
        var_760_1 = &var_518;
        var_768_1 = 0x100;
        result = sub_140008c94(nullptr, *(arg1 + 0x220), 0x200, &var_718, var_768_1, var_760_1, 
            0x100, *(arg1 + 4), 0);
        uint16_t (* rdx_4)[0x200] = &var_418;
        void* rcx_3 = arg1 + 0x19;
        int64_t i_3;
        
        do
        {
            if (*rdx_4 & 1)
            {
                *rcx_3 |= 0x10;
                result = *(&var_618 - arg1 + rcx_3 - 0x19);
                *(rcx_3 + 0x100) = result;
            }
            else if (!(*rdx_4 & 2))
                *(rcx_3 + 0x100) = 0;
            else
            {
                *rcx_3 |= 0x20;
                result = *(&var_518 - arg1 + rcx_3 - 0x19);
                *(rcx_3 + 0x100) = result;
            }
            
            rcx_3 += 1;
            rdx_4 = &(*rdx_4)[1];
            i_3 = i_4;
            i_4 -= 1;
        } while (i_3 != 1);
    }
    
    __security_check_cookie(rax_1 ^ &var_788);
    return result;
}

uint64_t sub_1400061cc(uint32_t arg1, char arg2, void* arg3, int64_t* arg4)
{
    int64_t* arg_20 = arg4;
    void* arg_18 = arg3;
    int64_t rsi;
    rsi = arg2;
    update_thread_multibyte_data_internal(arg3, *arg4);
    uint32_t rax = sub_140005ed8(arg1);
    
    if (rax == *(*(arg_18 + 0x88) + 4))
        return 0;
    
    int128_t* rax_2 = sub_140004aa0(0x228);
    int128_t* rbx_1 = rax_2;
    int32_t rdi_1;
    
    if (!rax_2)
        rdi_1 = -1;
    else
    {
        int64_t i_1 = 4;
        int128_t* rcx_3 = rbx_1;
        int128_t* rax_4 = *(arg_18 + 0x88);
        int64_t i;
        
        do
        {
            *rcx_3 = *rax_4;
            rcx_3[1] = rax_4[1];
            rcx_3[2] = rax_4[2];
            rcx_3[3] = rax_4[3];
            rcx_3[4] = rax_4[4];
            rcx_3[5] = rax_4[5];
            rcx_3[6] = rax_4[6];
            rcx_3 = &rcx_3[8];
            int128_t zmm1 = rax_4[7];
            rax_4 = &rax_4[8];
            rcx_3[-1] = zmm1;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
        *rcx_3 = *rax_4;
        rcx_3[1] = rax_4[1];
        rcx_3[2] = rax_4[2];
        *rbx_1 &= i_1;
        int32_t rax_6 = sub_1400064c4(rax, rbx_1);
        rdi_1 = rax_6;
        
        if (rax_6 != 0xffffffff)
        {
            if (!rsi)
                Concurrency::details::WinRT::Initialize();
            
            int32_t* rcx_6 = *(arg_18 + 0x88);
            int32_t rax_9 = *rcx_6;
            *rcx_6 -= 1;
            
            if (rax_9 == 1)
            {
                int64_t rcx_7 = *(arg_18 + 0x88);
                
                if (rcx_7 != &data_140016050)
                    _free_base(rcx_7);
            }
            
            *rbx_1 = 1;
            int128_t* rcx_8 = rbx_1;
            rbx_1 = nullptr;
            *(arg_18 + 0x88) = rcx_8;
            
            if (!(*(arg_18 + 0x3a8) & 2) && !(*data_1400167a0 & 1))
            {
                void** var_28 = &arg_18;
                int64_t** var_20_1 = &arg_20;
                int32_t var_34 = 5;
                int32_t var_30 = 5;
                void var_38;
                sub_140005d10(&var_38, &var_30, &var_28, &var_34);
                
                if (rsi)
                    data_1400166f0 = *arg_20;
            }
        }
        else
        {
            *_errno() = 0x16;
            rdi_1 = -1;
        }
    }
    
    _free_base(rbx_1);
    return rdi_1;
}

int32_t* update_thread_multibyte_data_internal(void* arg1, int32_t* arg2)
{
    int32_t* result;
    
    if (!(*(arg1 + 0x3a8) & data_1400167a0) || !*(arg1 + 0x90))
    {
        __vcrt_unlock(5);
        result = *(arg1 + 0x88);
        
        if (result != arg2)
        {
            if (result)
            {
                int32_t rax_1 = *result;
                *result -= 1;
                
                if (rax_1 == 1 && result != &data_140016050)
                    _free_base(result);
            }
            
            *(arg1 + 0x88) = arg2;
            *arg2 += 1;
            result = arg2;
        }
        
        __vcrt_lock(5);
    }
    else
        result = *(arg1 + 0x88);
    
    if (result)
        return result;
    
    abort();
    /* no return */
}

uint64_t __acrt_initialize_multibyte()
{
    if (!data_1400173bc)
    {
        data_1400173b0 = &data_140016390;
        data_1400173a0 = &data_140016050;
        data_1400173a8 = &data_140016280;
        sub_1400061cc(0xfffffffd, 1, sub_140005458(), &data_1400173a0);
        data_1400173bc = 1;
    }
    
    uint64_t result;
    result = 1;
    return result;
}

int64_t sub_1400064a8()
{
    /* tailcall */
    return update_thread_multibyte_data_internal(sub_14000538c(), data_1400173a0);
}

int64_t sub_1400064c4(uint32_t arg1, void* arg2)
{
    void var_68;
    int64_t rax_1 = __security_cookie ^ &var_68;
    uint32_t CodePage = sub_140005ed8(arg1);
    wchar16 const* const rsi = nullptr;
    int64_t result;
    
    if (CodePage)
    {
        int32_t i = 0;
        void* rax_2 = &data_1400164a0;
        
        do
        {
            if (*rax_2 == CodePage)
            {
                memset(arg2 + 0x18, 0, 0x101);
                void* r14_1 = &data_140016490;
                int64_t j_3 = 4;
                uint64_t r11_2 = i * 0x30;
                void* r9_1 = &data_1400164b0 + r11_2;
                int64_t j;
                
                do
                {
                    void* rdx_2 = r9_1;
                    
                    if (*r9_1)
                    {
                        while (*(rdx_2 + 1))
                        {
                            uint32_t r8_1 = *rdx_2;
                            
                            if (r8_1 <= *(rdx_2 + 1))
                            {
                                uint64_t r10_1 = r8_1 + 1;
                                
                                while (r10_1 < 0x101)
                                {
                                    uint32_t rax_11;
                                    rax_11 = *r14_1;
                                    r8_1 += 1;
                                    *(r10_1 + arg2 + 0x18) |= rax_11;
                                    r10_1 = r10_1 + 1;
                                    
                                    if (r8_1 > *(rdx_2 + 1))
                                        break;
                                }
                            }
                            
                            rdx_2 += 2;
                            
                            if (!*rdx_2)
                                break;
                        }
                    }
                    
                    r9_1 += 8;
                    r14_1 += 1;
                    j = j_3;
                    j_3 -= 1;
                } while (j != 1);
                *(arg2 + 4) = CodePage;
                *(arg2 + 8) = 1;
                
                if (CodePage == 0x3a4)
                    rsi = u"ja-JP";
                else if (CodePage == 0x3a8)
                    rsi = u"zh-CN";
                else if (CodePage == 0x3b5)
                    rsi = u"ko-KR";
                else if (CodePage == 0x3b6)
                    rsi = u"zh-TW";
                
                *(arg2 + 0x220) = rsi;
                void* rcx_10 = arg2 + 0xc;
                int64_t j_2 = 6;
                int64_t j_1;
                
                do
                {
                    *rcx_10 = *(r11_2 - arg2 + &data_1400164a0 + rcx_10 - 8);
                    rcx_10 += 2;
                    j_1 = j_2;
                    j_2 -= 1;
                } while (j_1 != 1);
                goto label_14000673e;
            }
            
            i += 1;
            rax_2 += 0x30;
        } while (i < 5);
        
        if (CodePage - 0xfde8 <= 1)
            result = 0xffffffff;
        else
        {
            CPINFO cPInfo;
            
            if (!IsValidCodePage(CodePage))
                result = 0xffffffff;
            else if (GetCPInfo(CodePage, &cPInfo))
            {
                memset(arg2 + 0x18, 0, 0x101);
                *(arg2 + 4) = CodePage;
                *(arg2 + 0x220) = 0;
                
                if (cPInfo.MaxCharSize <= 1)
                    *(arg2 + 8) = 0;
                else
                {
                    var_42;
                    void* rcx_4 = &var_42;
                    
                    if (cPInfo.LeadByte[0])
                    {
                        while (*(rcx_4 + 1))
                        {
                            uint32_t rax_6 = *(rcx_4 + 1);
                            uint32_t rdx_1 = *rcx_4;
                            
                            if (rdx_1 <= rax_6)
                            {
                                uint64_t rdi_1 = rdx_1 + 1;
                                uint64_t i_4 = 1 + rax_6 - rdx_1;
                                uint64_t i_1;
                                
                                do
                                {
                                    *(rdi_1 + arg2 + 0x18) |= 4;
                                    rdi_1 = rdi_1 + 1;
                                    i_1 = i_4;
                                    i_4 -= 1;
                                } while (i_1 != 1);
                            }
                            
                            rcx_4 += 2;
                            
                            if (!*rcx_4)
                                break;
                        }
                    }
                    
                    void* rax_8 = arg2 + 0x1a;
                    int64_t i_3 = 0xfe;
                    int64_t i_2;
                    
                    do
                    {
                        *rax_8 |= 8;
                        rax_8 += 1;
                        i_2 = i_3;
                        i_3 -= 1;
                    } while (i_2 != 1);
                    int32_t rcx_5 = *(arg2 + 4);
                    wchar16 const* const rax_9;
                    
                    if (rcx_5 == 0x3a4)
                        rax_9 = u"ja-JP";
                    else if (rcx_5 == 0x3a8)
                        rax_9 = u"zh-CN";
                    else if (rcx_5 == 0x3b5)
                        rax_9 = u"ko-KR";
                    else if (rcx_5 == 0x3b6)
                        rax_9 = u"zh-TW";
                    else
                        rax_9 = nullptr;
                    
                    *(arg2 + 0x220) = rax_9;
                    *(arg2 + 8) = 1;
                }
                
                __builtin_memset(arg2 + 0xc, 0, 0xc);
                label_14000673e:
                sub_140005fe8(arg2);
                result = 0;
            }
            else if (data_1400173b8)
            {
                sub_140005f58(arg2);
                result = 0;
            }
            else
                result = 0xffffffff;
        }
    }
    else
    {
        sub_140005f58(arg2);
        result = 0;
    }
    
    __security_check_cookie(rax_1 ^ &var_68);
    return result;
}

PWSTR __acrt_initialize_command_line()
{
    data_1400173d8 = GetCommandLineA();
    data_1400173e0 = GetCommandLineW();
    PWSTR result;
    result = 1;
    return result;
}

int128_t* __dcrt_get_wide_environment_from_os()
{
    PWSTR penv_1 = GetEnvironmentStringsW();
    int128_t* result = nullptr;
    PWSTR penv = penv_1;
    
    if (penv_1)
    {
        while (*penv_1)
        {
            int64_t rcx_1 = -1;
            
            do
                rcx_1 += 1;
             while (penv_1[rcx_1]);
            
            penv_1 = &penv_1[rcx_1 + 1];
        }
        
        int64_t __saved_rsi_1 = ((penv_1 - penv + 2) >> 1) * 2;
        int128_t* result_1 = sub_140004aa0(__saved_rsi_1);
        
        if (result_1)
        {
            memcpy(result_1, penv, __saved_rsi_1);
            result = result_1;
        }
        
        _free_base(0);
        FreeEnvironmentStringsW(penv);
    }
    
    return result;
}

int64_t sub_14000682c()
{
    uint64_t rbx = 0;
    int32_t result;
    
    while (true)
    {
        if (!__vcrt_InitializeCriticalSectionEx(&data_1400173f0 + rbx * 0x28, 0xfa0, 0))
        {
            sub_140006890();
            result = 0;
            break;
        }
        
        data_140017620 += 1;
        rbx = rbx + 1;
        
        if (rbx >= 0xe)
        {
            result = 1;
            break;
        }
    }
    
    return result;
}

int64_t __vcrt_unlock(int32_t arg1)
{
    /* tailcall */
    return EnterCriticalSection(&data_1400173f0 + arg1 * 0x28);
}

int64_t sub_140006890()
{
    uint64_t rbx = data_140017620;
    
    while (rbx)
    {
        rbx = rbx - 1;
        DeleteCriticalSection(&data_1400173f0 + rbx * 0x28);
        data_140017620 -= 1;
    }
    
    int64_t result;
    result = 1;
    return result;
}

int64_t __vcrt_lock(int32_t arg1)
{
    /* tailcall */
    return LeaveCriticalSection(&data_1400173f0 + arg1 * 0x28);
}

uint64_t sub_1400068e4()
{
    int32_t arg_8 = 0;
    __acrt_SetThreadStackGuarantee(&arg_8);
    int32_t rbx;
    rbx = arg_8 != 1;
    return rbx;
}

void* __acrt_lowio_create_handle_array()
{
    void* result_1 = _calloc_base(0x40, 0x40);
    void* result = nullptr;
    
    if (result_1)
    {
        if (result_1 != result_1 + 0x1000)
        {
            int64_t* rdi_1 = result_1 + 0x30;
            
            do
            {
                __vcrt_InitializeCriticalSectionEx(&rdi_1[-6], 0xfa0, 0);
                rdi_1[-1] = -1;
                *rdi_1 = 0;
                rdi_1[1] = 0xa0a0000;
                *(rdi_1 + 0xc) = 0xa;
                *(rdi_1 + 0xd) &= 0xf8;
                *(rdi_1 + 0xe) = 0;
                rdi_1 = &rdi_1[8];
            } while (&rdi_1[-6] != result_1 + 0x1000);
        }
        
        result = result_1;
    }
    
    _free_base(0);
    return result;
}

void __acrt_lowio_destroy_handle_array(CRITICAL_SECTION* arg1)
{
    if (arg1)
    {
        CRITICAL_SECTION* lpCriticalSection = arg1;
        
        if (arg1 != arg1 + 0x1000)
        {
            do
            {
                DeleteCriticalSection(lpCriticalSection);
                lpCriticalSection += 0x40;
            } while (lpCriticalSection != arg1 + 0x1000);
        }
        
        _free_base(arg1);
    }
}

uint64_t __acrt_lowio_ensure_fh_exists(int32_t arg1)
{
    int32_t rbx = 0;
    int32_t rax;
    rax = arg1 < 0x2000;
    
    if (rax)
    {
        __vcrt_unlock(7);
        int64_t rdi_1 = 0;
        int64_t var_18_1 = 0;
        int32_t rax_3 = data_140017a30;
        
        while (arg1 >= rax_3)
        {
            if (!(&data_140017630)[rdi_1])
            {
                void* rax_4 = __acrt_lowio_create_handle_array();
                (&data_140017630)[rdi_1] = rax_4;
                
                if (!rax_4)
                {
                    rbx = rax_4 + 0xc;
                    break;
                }
                
                rax_3 = data_140017a30 + 0x40;
                data_140017a30 = rax_3;
            }
            
            rdi_1 += 1;
            int64_t var_18_2 = rdi_1;
        }
        
        __vcrt_lock(7);
    }
    else
    {
        rbx = 9;
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    
    return rbx;
}

int64_t __acrt_lowio_unlock_fh(int32_t arg1)
{
    int64_t rcx_4 = arg1;
    /* tailcall */
    return EnterCriticalSection(((rcx_4 & 0x3f) << 6) + (&data_140017630)[rcx_4 >> 6]);
}

int64_t sub_140006ad0(int32_t arg1)
{
    int64_t rcx_4 = arg1;
    /* tailcall */
    return LeaveCriticalSection(((rcx_4 & 0x3f) << 6) + (&data_140017630)[rcx_4 >> 6]);
}

int64_t sub_140006af4(int32_t arg1)
{
    int64_t rbx = arg1;
    
    if (arg1 >= 0 && rbx < data_140017a30)
    {
        int64_t rsi_2 = rbx >> 6;
        uint64_t rdi_3 = (rbx & 0x3f) << 6;
        int64_t rax_1 = (&data_140017630)[rsi_2];
        
        if (*(rax_1 + rdi_3 + 0x38) & 1 && *(rax_1 + rdi_3 + 0x28) != -1)
        {
            int32_t rax_2 = sub_1400037c4();
            
            if (rax_2 == 1)
            {
                if (!rbx)
                    SetStdHandle(STD_INPUT_HANDLE, nullptr);
                else if (rbx == rax_2)
                    SetStdHandle(STD_OUTPUT_HANDLE, nullptr);
                else if (rbx - rax_2 == rax_2)
                    SetStdHandle(STD_ERROR_HANDLE, nullptr);
            }
            
            *((&data_140017630)[rsi_2] + rdi_3 + 0x28) = -1;
            return 0;
        }
    }
    
    *_errno() = 9;
    *__doserrno() = 0;
    return 0xffffffff;
}

int64_t sub_140006bb0(int32_t arg1)
{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_140017a30)
        {
            int64_t rdx_1 = arg1;
            uint64_t rdx_3 = (rdx_1 & 0x3f) << 6;
            int64_t rax_5 = (&data_140017630)[rdx_1 >> 6];
            
            if (*(rax_5 + rdx_3 + 0x38) & 1)
                return *(rax_5 + rdx_3 + 0x28);
        }
        
        *__doserrno() = 0;
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    else
    {
        *__doserrno() = 0;
        *_errno() = 9;
    }
    
    return -1;
}

BYTE* sub_140006c28()
{
    STARTUPINFOW startupInfo;
    BYTE* lpReserved2 = GetStartupInfoW(&startupInfo);
    
    if (startupInfo.cbReserved2)
    {
        lpReserved2 = startupInfo.lpReserved2;
        
        if (lpReserved2)
        {
            void* rsi_1 = &lpReserved2[4];
            uint64_t i_1 = 0x2000;
            void* rbx_2 = *lpReserved2 + rsi_1;
            
            if (*lpReserved2 < 0x2000)
                i_1 = *lpReserved2;
            
            lpReserved2 = __acrt_lowio_ensure_fh_exists(i_1);
            
            if (i_1 > data_140017a30)
                i_1 = data_140017a30;
            
            if (i_1)
            {
                int64_t rbp_1 = 0;
                uint64_t i;
                
                do
                {
                    if (*rbx_2 != -1 && *rbx_2 != -2 && *rsi_1 & 1)
                    {
                        if (!(*rsi_1 & 8))
                            lpReserved2 = GetFileType(*rbx_2);
                        
                        if (*rsi_1 & 8 || lpReserved2)
                        {
                            void* rcx_6 = ((rbp_1 & 0x3f) << 6) + (&data_140017630)[rbp_1 >> 6];
                            *(rcx_6 + 0x28) = *rbx_2;
                            lpReserved2 = *rsi_1;
                            *(rcx_6 + 0x38) = lpReserved2;
                        }
                    }
                    
                    rbp_1 += 1;
                    rsi_1 += 1;
                    rbx_2 += 8;
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
            }
        }
    }
    
    return lpReserved2;
}

void* const sub_140006d14()
{
    int32_t i = 0;
    int64_t* r14 = nullptr;
    void* const result;
    
    do
    {
        int64_t i_1 = i;
        void* rbx_3 = ((i_1 & 0x3f) << 6) + (&data_140017630)[i_1 >> 6];
        result = *(rbx_3 + 0x28) + 2;
        
        if (result <= 1)
        {
            *(rbx_3 + 0x38) = 0x81;
            enum STD_HANDLE nStdHandle;
            
            if (!i)
                nStdHandle = STD_INPUT_HANDLE;
            else if (i == 1)
                nStdHandle = STD_OUTPUT_HANDLE;
            else
                nStdHandle = STD_ERROR_HANDLE;
            
            HANDLE hFile = GetStdHandle(nStdHandle);
            
            if (hFile + 1 <= 1)
                result = nullptr;
            else
                result = GetFileType(hFile);
            
            if (!result)
            {
                *(rbx_3 + 0x38) |= 0x40;
                *(rbx_3 + 0x28) = -2;
                result = data_140017c38;
                
                if (result)
                {
                    result = *(r14 + result);
                    *(result + 0x18) = 0xfffffffe;
                }
            }
            else
            {
                uint32_t rcx_4 = result;
                *(rbx_3 + 0x28) = hFile;
                
                if (rcx_4 == 2)
                    *(rbx_3 + 0x38) |= 0x40;
                else if (rcx_4 == 3)
                    *(rbx_3 + 0x38) |= 8;
            }
        }
        else
            *(rbx_3 + 0x38) |= 0x80;
        
        i += 1;
        r14 = &r14[1];
    } while (i != 3);
    
    return result;
}

int64_t __acrt_initialize_lowio()
{
    __vcrt_unlock(7);
    char rbx = 0;
    
    if (!__acrt_lowio_ensure_fh_exists(0))
    {
        sub_140006c28();
        sub_140006d14();
        rbx = 1;
    }
    
    __vcrt_lock(7);
    int64_t result;
    result = rbx;
    return result;
}

int64_t __acrt_uninitialize_lowio()
{
    for (int64_t i = 0; i < 0x400; i += 8)
    {
        CRITICAL_SECTION* rcx_1 = *(i + &data_140017630);
        
        if (rcx_1)
        {
            __acrt_lowio_destroy_handle_array(rcx_1);
            *(i + &data_140017630) = 0;
        }
    }
    
    int64_t result;
    result = 1;
    return result;
}

void __acrt_locale_free_monetary(void* arg1)
{
    if (arg1)
    {
        int64_t rcx = *(arg1 + 0x18);
        
        if (rcx != data_140016718)
            _free_base(rcx);
        
        int64_t rcx_1 = *(arg1 + 0x20);
        
        if (rcx_1 != data_140016720)
            _free_base(rcx_1);
        
        int64_t rcx_2 = *(arg1 + 0x28);
        
        if (rcx_2 != data_140016728)
            _free_base(rcx_2);
        
        int64_t rcx_3 = *(arg1 + 0x30);
        
        if (rcx_3 != data_140016730)
            _free_base(rcx_3);
        
        int64_t rcx_4 = *(arg1 + 0x38);
        
        if (rcx_4 != data_140016738)
            _free_base(rcx_4);
        
        int64_t rcx_5 = *(arg1 + 0x40);
        
        if (rcx_5 != data_140016740)
            _free_base(rcx_5);
        
        int64_t rcx_6 = *(arg1 + 0x48);
        
        if (rcx_6 != data_140016748)
            _free_base(rcx_6);
        
        int64_t rcx_7 = *(arg1 + 0x68);
        
        if (rcx_7 != data_140016768)
            _free_base(rcx_7);
        
        int64_t rcx_8 = *(arg1 + 0x70);
        
        if (rcx_8 != data_140016770)
            _free_base(rcx_8);
        
        int64_t rcx_9 = *(arg1 + 0x78);
        
        if (rcx_9 != data_140016778)
            _free_base(rcx_9);
        
        int64_t rcx_10 = *(arg1 + 0x80);
        
        if (rcx_10 != data_140016780)
            _free_base(rcx_10);
        
        int64_t rcx_11 = *(arg1 + 0x88);
        
        if (rcx_11 != data_140016788)
            _free_base(rcx_11);
        
        int64_t rcx_12 = *(arg1 + 0x90);
        
        if (rcx_12 != data_140016790)
            _free_base(rcx_12);
    }
}

void __acrt_locale_free_numeric(int64_t* arg1)
{
    if (arg1)
    {
        int64_t rcx = *arg1;
        
        if (rcx != data_140016700)
            _free_base(rcx);
        
        int64_t rcx_1 = arg1[1];
        
        if (rcx_1 != data_140016708)
            _free_base(rcx_1);
        
        int64_t rcx_2 = arg1[2];
        
        if (rcx_2 != data_140016710)
            _free_base(rcx_2);
        
        int64_t rcx_3 = arg1[0xb];
        
        if (rcx_3 != data_140016758)
            _free_base(rcx_3);
        
        int64_t rcx_4 = arg1[0xc];
        
        if (rcx_4 != data_140016760)
            _free_base(rcx_4);
    }
}

void* free_crt_array_internal(int64_t* arg1, int64_t arg2)
{
    int64_t rdi = 0;
    void* result = &arg1[arg2];
    int64_t* rbx = arg1;
    uint64_t rsi_3 = (result - arg1 + 7) >> 3;
    
    if (arg1 > result)
        rsi_3 = 0;
    
    if (rsi_3)
    {
        do
        {
            result = _free_base(*rbx);
            rdi += 1;
            rbx = &rbx[1];
        } while (rdi != rsi_3);
    }
    
    return result;
}

void __acrt_locale_free_time(int64_t* arg1)
{
    if (arg1)
    {
        free_crt_array_internal(arg1, 7);
        free_crt_array_internal(&arg1[7], 7);
        free_crt_array_internal(&arg1[0xe], 0xc);
        free_crt_array_internal(&arg1[0x1a], 0xc);
        free_crt_array_internal(&arg1[0x26], 2);
        _free_base(arg1[0x28]);
        _free_base(arg1[0x29]);
        _free_base(arg1[0x2a]);
        free_crt_array_internal(&arg1[0x2c], 7);
        free_crt_array_internal(&arg1[0x33], 7);
        free_crt_array_internal(&arg1[0x3a], 0xc);
        free_crt_array_internal(&arg1[0x46], 0xc);
        free_crt_array_internal(&arg1[0x52], 2);
        _free_base(arg1[0x54]);
        _free_base(arg1[0x55]);
        _free_base(arg1[0x56]);
        _free_base(arg1[0x57]);
    }
}

int64_t ___lc_codepage_func()
{
    void** rax = sub_14000538c();
    int64_t* arg_8 = rax[0x12];
    __acrt_update_locale_info(rax, &arg_8);
    return *arg_8;
}

uint64_t wcsncmp(int16_t* arg1, int16_t* arg2, int64_t arg3)
{
    if (!arg3)
        return 0;
    
    while (true)
    {
        int64_t temp0_1 = arg3;
        arg3 -= 1;
        int16_t rax_2;
        
        if (temp0_1 != 1)
            rax_2 = *arg1;
        
        if (temp0_1 == 1 || !rax_2 || rax_2 != *arg2)
            return *arg1 - *arg2;
        
        arg1 = &arg1[1];
        arg2 = &arg2[1];
    }
}

int16_t* sub_1400071c0(int16_t* arg1, int16_t* arg2)
{
    while (*arg1)
    {
        int16_t* rax_1 = arg2;
        
        if (*arg2)
        {
            int16_t i = *arg2;
            
            do
            {
                if (i == *arg1)
                    return arg1;
                
                rax_1 = &rax_1[1];
                i = *rax_1;
            } while (i);
        }
        
        arg1 = &arg1[1];
    }
    
    return 0;
}

uint64_t __acrt_GetStringTypeA(int128_t* arg1, uint32_t arg2, uint8_t* arg3, int32_t arg4, uint16_t* arg5, uint32_t arg6, int32_t arg7)
{
    int64_t __saved_rbp_1;
    int64_t __saved_rbp = __saved_rbp_1;
    int64_t __saved_r12_1;
    int64_t __saved_r12 = __saved_r12_1;
    int64_t __saved_r13_1;
    int64_t __saved_r13 = __saved_r13_1;
    int64_t __saved_r14_1;
    int64_t __saved_r14 = __saved_r14_1;
    int64_t __saved_r15_1;
    int64_t __saved_r15 = __saved_r15_1;
    void var_88;
    void* rsp_1 = &var_88;
    int64_t __saved_rbx_1;
    int64_t __saved_rbx = __saved_rbx_1;
    int64_t __saved_rsi_1;
    int64_t __saved_rsi = __saved_rsi_1;
    int64_t __saved_rdi_1;
    int64_t __saved_rdi = __saved_rdi_1;
    void* var_58;
    int64_t rax_1 = __security_cookie ^ &var_58;
    int32_t rdx_1 = sub_140004c30(&var_58, arg1);
    uint32_t CodePage = arg6;
    void* var_50;
    
    if (!CodePage)
        CodePage = *(var_50 + 0xc);
    int32_t temp0 = arg7;
    arg7 = -(arg7);
    int64_t rax_3 =
        MultiByteToWideChar(CodePage, ((rdx_1 - rdx_1) & 8) + 1, arg3, arg4, nullptr, 0);
    int64_t r14 = rax_3;
    BOOL rdi;
    
    if (rax_3)
    {
        int64_t rdi_2 = r14 * 2;
        int64_t rax_4 = rax_3 - rax_3;
        void* lpSrcStr;
        
        if (!((rdi_2 + 0x10) & rax_4))
        {
            lpSrcStr = nullptr;
            label_14000730b:
            
            if (!lpSrcStr)
                rdi = 0;
            else
            {
                memset(lpSrcStr, 0, rdi_2);
                *(rsp_1 + 0x28) = r14;
                *(rsp_1 + 0x20) = lpSrcStr;
                int32_t cchSrc = MultiByteToWideChar(/* nop */, /* nop */, /* nop */, /* nop */);
                
                if (!cchSrc)
                    rdi = 0;
                else
                    rdi = GetStringTypeW(arg2, lpSrcStr, cchSrc, arg5);
            }
        }
        else
        {
            if (((rax_4 - rax_4) & (rdi_2 + 0x10)) > 0x400)
            {
                void* lpSrcStr_1 = sub_140004aa0((rdi_2 + 0x10 - (rdi_2 + 0x10)) & (rdi_2 + 0x10));
                lpSrcStr = lpSrcStr_1;
                
                if (!lpSrcStr_1)
                    goto label_14000730b;
                
                *lpSrcStr_1 = 0xdddd;
                label_140007303:
                lpSrcStr += 0x10;
                goto label_14000730b;
            }
            
            int64_t rcx_5 = (rdi_2 + 0x10 - (rdi_2 + 0x10)) & (rdi_2 + 0x10);
            int64_t rax_8 = rcx_5 + 0xf;
            
            if (rax_8 <= rcx_5)
                rax_8 = 0xffffffffffffff0;
            
            int64_t rax_9 = rax_8 & 0xfffffffffffffff0;
            __chkstk(rax_9);
            rsp_1 = &var_88 - rax_9;
            lpSrcStr = rsp_1 + 0x30;
            
            if (lpSrcStr)
            {
                *lpSrcStr = 0xcccc;
                goto label_140007303;
            }
            
            rdi = 0;
        }
        
        if (lpSrcStr && *(lpSrcStr - 0x10) == 0xdddd)
            _free_base(lpSrcStr - 0x10);
    }
    else
        rdi = 0;
    
    char var_40;
    
    if (var_40)
    {
        void* rax_11 = var_58;
        *(rax_11 + 0x3a8) &= 0xfffffffd;
    }
    
    __security_check_cookie(rax_1 ^ &var_58);
    return rdi;
}

int64_t sub_1400073ac(void* arg1)
{
    *(arg1 + 0x10) += 1;
    int32_t* rax = *(arg1 + 0xe0);
    
    if (rax)
        *rax += 1;
    
    int32_t* rax_1 = *(arg1 + 0xf0);
    
    if (rax_1)
        *rax_1 += 1;
    
    int32_t* rax_2 = *(arg1 + 0xe8);
    
    if (rax_2)
        *rax_2 += 1;
    
    int32_t* rax_3 = *(arg1 + 0x100);
    
    if (rax_3)
        *rax_3 += 1;
    
    void* rax_4 = arg1 + 0x38;
    int64_t i_1 = 6;
    int64_t i;
    
    do
    {
        if (*(rax_4 - 0x10) != &data_1400166f8)
        {
            int32_t* rdx_1 = *rax_4;
            
            if (rdx_1)
                *rdx_1 += 1;
        }
        
        if (*(rax_4 - 0x18))
        {
            int32_t* rdx_2 = *(rax_4 - 8);
            
            if (rdx_2)
                *rdx_2 += 1;
        }
        
        rax_4 += 0x20;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    /* tailcall */
    return sub_1400075b0(*(arg1 + 0x120));
}

int64_t __acrt_free_locale(void* arg1)
{
    int64_t rax = *(arg1 + 0xf8);
    
    if (rax && rax != &data_140016700)
    {
        int32_t* rax_1 = *(arg1 + 0xe0);
        
        if (rax_1 && !*rax_1)
        {
            int32_t* rcx = *(arg1 + 0xf0);
            
            if (rcx && !*rcx)
            {
                _free_base(rcx);
                __acrt_locale_free_monetary(*(arg1 + 0xf8));
            }
            
            int32_t* rcx_2 = *(arg1 + 0xe8);
            
            if (rcx_2 && !*rcx_2)
            {
                _free_base(rcx_2);
                __acrt_locale_free_numeric(*(arg1 + 0xf8));
            }
            
            _free_base(*(arg1 + 0xe0));
            _free_base(*(arg1 + 0xf8));
        }
    }
    
    int32_t* rax_2 = *(arg1 + 0x100);
    
    if (rax_2 && !*rax_2)
    {
        _free_base(*(arg1 + 0x108) - 0xfe);
        _free_base(*(arg1 + 0x110) - 0x80);
        _free_base(*(arg1 + 0x118) - 0x80);
        _free_base(*(arg1 + 0x100));
    }
    
    sub_1400075d8(*(arg1 + 0x120));
    void* rsi = arg1 + 0x128;
    int64_t i_1 = 6;
    void* rdi = arg1 + 0x38;
    int64_t i;
    
    do
    {
        if (*(rdi - 0x10) != &data_1400166f8)
        {
            int32_t* rcx_14 = *rdi;
            
            if (rcx_14 && !*rcx_14)
            {
                _free_base(rcx_14);
                _free_base(*rsi);
            }
        }
        
        if (*(rdi - 0x18))
        {
            int32_t* rcx_16 = *(rdi - 8);
            
            if (rcx_16 && !*rcx_16)
                _free_base(rcx_16);
        }
        
        rsi += 8;
        rdi += 0x20;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    /* tailcall */
    return _free_base(arg1);
}

uint64_t sub_1400075b0(void* arg1)
{
    if (!arg1 || arg1 == &data_14000d610)
        return 0x7fffffff;
    
    int32_t rax = *(arg1 + 0x15c);
    *(arg1 + 0x15c) += 1;
    return rax + 1;
}

void sub_1400075d8(int64_t* arg1)
{
    if (arg1 && arg1 != &data_14000d610 && !*(arg1 + 0x15c))
    {
        __acrt_locale_free_time(arg1);
        _free_base(arg1);
    }
}

uint64_t sub_140007610(void* arg1)
{
    if (!arg1 || arg1 == &data_14000d610)
        return 0x7fffffff;
    
    int32_t rax = *(arg1 + 0x15c);
    *(arg1 + 0x15c) -= 1;
    return rax - 1;
}

void __acrt_release_locale_ref(void* arg1)
{
    if (arg1)
    {
        *(arg1 + 0x10) -= 1;
        int32_t* rax_1 = *(arg1 + 0xe0);
        
        if (rax_1)
            *rax_1 -= 1;
        
        int32_t* rax_2 = *(arg1 + 0xf0);
        
        if (rax_2)
            *rax_2 -= 1;
        
        int32_t* rax_3 = *(arg1 + 0xe8);
        
        if (rax_3)
            *rax_3 -= 1;
        
        int32_t* rax_4 = *(arg1 + 0x100);
        
        if (rax_4)
            *rax_4 -= 1;
        
        void* rax_5 = arg1 + 0x38;
        int64_t i_1 = 6;
        int64_t i;
        
        do
        {
            if (*(rax_5 - 0x10) != &data_1400166f8)
            {
                int32_t* rdx_1 = *rax_5;
                
                if (rdx_1)
                    *rdx_1 -= 1;
            }
            
            if (*(rax_5 - 0x18))
            {
                int32_t* rdx_2 = *(rax_5 - 8);
                
                if (rdx_2)
                    *rdx_2 -= 1;
            }
            
            rax_5 += 0x20;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
        sub_140007610(*(arg1 + 0x120));
    }
}

void* __acrt_update_thread_locale_data()
{
    void** rax = sub_14000538c();
    void* result;
    
    if (rax[0x75] & data_1400167a0)
        result = rax[0x12];
    
    if (!(rax[0x75] & data_1400167a0) || !result)
    {
        __vcrt_unlock(4);
        result = sub_140007750(&rax[0x12], data_140017a38);
        __vcrt_lock(4);
        
        if (!result)
        {
            abort();
            /* no return */
        }
    }
    
    return result;
}

void* const sub_140007750(int64_t* arg1, void* arg2)
{
    if (!arg2 || !arg1)
        return nullptr;
    
    void* rbx_1 = *arg1;
    
    if (rbx_1 == arg2)
        return arg2;
    
    *arg1 = arg2;
    sub_1400073ac(arg2);
    
    if (rbx_1)
    {
        __acrt_release_locale_ref(rbx_1);
        
        if (!*(rbx_1 + 0x10) && rbx_1 != &data_140016590)
            __acrt_free_locale(rbx_1);
    }
    
    return arg2;
}

int64_t try_get_function(int32_t arg1, PSTR arg2, int32_t* arg3, int64_t arg4)
{
    uint64_t r15 = arg1;
    int32_t* rbp = arg3;
    uint64_t __security_cookie_2 = __security_cookie;
    int64_t rcx;
    rcx = __security_cookie_2 & 0x3f;
    int64_t rdx_2 = RORQ(__security_cookie_2 ^ *((r15 << 3) + &data_140017ae0), rcx);
    
    if (rdx_2 != -1)
    {
        if (rdx_2)
            return rdx_2;
        
        HMODULE rbx_1;
        
        if (arg3 == arg4)
        {
            label_140007903:
            rbx_1 = nullptr;
        }
        else
        {
            while (true)
            {
                uint64_t rsi_1 = *rbp;
                rbx_1 = *((rsi_1 << 3) + &data_140017a40);
                
                if (!rbx_1)
                {
                    PWSTR lpLibFileName = (&data_14000e2a0)[rsi_1];
                    HMODULE rax_3 =
                        LoadLibraryExW(lpLibFileName, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
                    rbx_1 = rax_3;
                    
                    if (!rax_3)
                    {
                        enum WIN32_ERROR rax_4 = GetLastError();
                        
                        if (rax_4 != ERROR_INVALID_PARAMETER)
                            rbx_1 = nullptr;
                        else if (!wcsncmp(lpLibFileName, u"api-ms-", rax_4 - 0x50))
                            rbx_1 = nullptr;
                        else if (!wcsncmp(lpLibFileName, u"ext-ms-", rax_4 - 0x50))
                            rbx_1 = nullptr;
                        else
                            rbx_1 = LoadLibraryExW(lpLibFileName, nullptr, 0);
                    }
                    
                    if (rbx_1)
                    {
                        int64_t temp0_2 = *((rsi_1 << 3) + &data_140017a40);
                        *((rsi_1 << 3) + &data_140017a40) = rbx_1;
                        
                        if (temp0_2)
                            FreeLibrary(rbx_1);
                        
                        goto label_1400078ea;
                    }
                    
                    *((rsi_1 << 3) + &data_140017a40);
                    *((rsi_1 << 3) + &data_140017a40) = -1;
                }
                else if (rbx_1 != -1)
                {
                    label_1400078ea:
                    
                    if (rbx_1)
                    {
                        __security_cookie_2 = __security_cookie;
                        break;
                    }
                }
                
                rbp = &rbp[1];
                
                if (rbp == arg4)
                {
                    __security_cookie_2 = __security_cookie;
                    goto label_140007903;
                }
            }
        }
        
        if (rbx_1)
        {
            int64_t rax_2 = GetProcAddress(rbx_1, arg2);
            
            if (rax_2)
            {
                uint64_t __security_cookie_1 = __security_cookie;
                *((r15 << 3) + &data_140017ae0);
                *((r15 << 3) + &data_140017ae0) =
                    RORQ(rax_2, 0x40 - (__security_cookie_1 & 0x3f)) ^ __security_cookie_1;
                return rax_2;
            }
            
            __security_cookie_2 = __security_cookie;
        }
        
        *((r15 << 3) + &data_140017ae0);
        *((r15 << 3) + &data_140017ae0) =
            RORQ(-1, 0x40 - (__security_cookie_2 & 0x3f)) ^ __security_cookie_2;
    }
    
    return 0;
}

int64_t __acrt_SetThreadStackGuarantee(int64_t arg1)
{
    int64_t rax = try_get_function(0x1c, "AppPolicyGetProcessTerminationMe…", &data_14000e7b4, 
        "AppPolicyGetProcessTerminationMe…");
    
    if (!rax)
        return 0xc0000225;
    
    /* tailcall */
    return rax(-6, arg1);
}

int64_t __acrt_FlsAlloc(int64_t arg1)
{
    int64_t rax = try_get_function(3, "FlsAlloc", &data_14000e758, &data_14000e760);
    
    if (!rax)
        /* tailcall */
        return TlsAlloc();
    
    /* tailcall */
    return rax(arg1);
}

int64_t __acrt_FlsFree(uint32_t arg1)
{
    int64_t rax = try_get_function(4, "FlsFree", &data_14000e760, &data_14000e768);
    
    if (!rax)
        /* tailcall */
        return TlsFree(arg1);
    
    /* tailcall */
    return rax(arg1);
}

int64_t sub_140007a70(uint32_t arg1)
{
    int64_t rax = try_get_function(5, "FlsGetValue", &data_14000e768, &data_14000e770);
    
    if (!rax)
        /* tailcall */
        return TlsGetValue(arg1);
    
    /* tailcall */
    return rax(arg1);
}

int64_t sub_140007ab8(uint32_t arg1, int64_t arg2)
{
    int64_t rax = try_get_function(6, "FlsSetValue", &data_14000e770, &data_14000e778);
    
    if (!rax)
        return TlsSetValue(arg1, arg2);
    
    return rax(arg1, arg2);
}

int64_t __vcrt_InitializeCriticalSectionEx(CRITICAL_SECTION* arg1, uint32_t arg2, int32_t arg3)
{
    int64_t rax =
        try_get_function(0x12, "InitializeCriticalSectionEx", &data_14000e778, &data_14000e780);
    
    if (!rax)
        return InitializeCriticalSectionAndSpinCount(arg1, arg2);
    
    return rax(arg1, arg2, arg3);
}

int64_t sub_140007b70(int64_t arg1, uint32_t arg2, wchar16* arg3, int32_t arg4, PWSTR arg5, int32_t arg6, int64_t arg7, int64_t arg8, int64_t arg9)
{
    int64_t rax = try_get_function(0x14, "LCMapStringEx", &data_14000e780, "LCMapStringEx");
    
    if (!rax)
        return LCMapStringW(sub_140007c4c(arg1, 0), arg2, arg3, arg4, arg5, arg6);
    
    return rax(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

uint64_t sub_140007c4c(int64_t arg1, int32_t arg2)
{
    int64_t rax = try_get_function(0x16, "LocaleNameToLCID", &data_14000e798, "LocaleNameToLCID");
    
    if (!rax)
        return sub_140008df4(arg1);
    
    return rax(arg1, arg2);
}

int64_t __acrt_initialize_winapi_thunks()
{
    int64_t rcx;
    int64_t rdi;
    rdi = __memfill_u64(&data_140017ae0, __security_cookie, 0x22);
    int64_t result;
    result = 1;
    return result;
}

void* sub_140007cd4(char arg1)
{
    if (!arg1)
    {
        for (void* i = &data_140017a40; i != &data_140017ad8; i += 8)
        {
            HMODULE hLibModule = *i;
            
            if (hLibModule)
            {
                if (hLibModule != -1)
                    FreeLibrary(hLibModule);
                
                *i = 0;
            }
        }
    }
    
    void* result;
    result = 1;
    return result;
}

void* _recalloc_base(int64_t arg1, int64_t arg2, int64_t arg3)
{
    if (arg2 && COMBINE(0, -0x20) / arg2 < arg3)
    {
        *_errno() = 0xc;
        return nullptr;
    }
    
    int64_t rdi_1;
    
    if (!arg1)
        rdi_1 = 0;
    else
        rdi_1 = j__msize_base(arg1);
    
    uint64_t rbx_1 = arg2 * arg3;
    void* result = _realloc_base(arg1, rbx_1);
    
    if (result && rdi_1 < rbx_1)
        memset(result + rdi_1, 0, rbx_1 - rdi_1);
    
    return result;
}

HANDLE sub_140007db0()
{
    HANDLE result = GetProcessHeap();
    data_140017bf8 = result;
    result = result;
    return result;
}

int64_t sub_140007dcc()
{
    data_140017bf8 = 0;
    int64_t result;
    result = 1;
    return result;
}

void* __acrt_execute_initializers(int64_t* arg1, int64_t arg2)
{
    void* result;
    int64_t* rbx_1;
    
    if (arg1 != arg2)
    {
        rbx_1 = arg1;
        
        do
        {
            result = *rbx_1;
            
            if (result && !result())
                break;
            
            rbx_1 = &rbx_1[2];
        } while (rbx_1 != arg2);
    }
    
    if (arg1 == arg2 || rbx_1 == arg2)
        result = 1;
    else
    {
        if (rbx_1 != arg1)
        {
            void* rbx_2 = &rbx_1[-1];
            
            do
            {
                if (*(rbx_2 - 8))
                {
                    int64_t rax = *rbx_2;
                    
                    if (rax)
                        rax(0);
                }
                
                rbx_2 -= 0x10;
            } while (rbx_2 + 8 != arg1);
        }
        
        result = 0;
    }
    
    return result;
}

void* sub_140007e58(int64_t arg1, void* arg2)
{
    if (arg1 != arg2)
    {
        int64_t* rbx_1 = arg2 - 8;
        
        do
        {
            int64_t rax = *rbx_1;
            
            if (rax)
                rax(0);
            
            rbx_1 -= 0x10;
        } while (&rbx_1[1] != arg1);
    }
    
    void* result;
    result = 1;
    return result;
}

int64_t __crt_seh_guarded_call<class <lambda_c36588078e9f5dfd39652860aa6b3aaf>,class <lambda_ec61778202f4f5fc7e7711acc23c3bca>& __ptr64,class <lambda_dc9d2797ccde5d239b4a0efae8ebd7db>,void (__cdecl*)(int32_t)>::operator()<class <lambda_c36588078e9f5dfd39652860aa6b3aaf>,class <lambda_ec61778202f4f5fc7e7711acc23c3bca>& __ptr64,class <lambda_dc9d2797ccde5d239b4a0efae8ebd7db> >(int64_t arg1, int32_t* arg2, int64_t arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    uint64_t __security_cookie_1 = __security_cookie;
    int64_t result = RORQ(__security_cookie_1 ^ data_140017c10, __security_cookie_1 & 0x3f);
    __vcrt_lock(*arg4);
    return result;
}

int64_t __acrt_get_sigabrt_handler()
{
    int32_t arg_10 = 3;
    int32_t arg_18 = 3;
    void arg_8;
    return __crt_seh_guarded_call<class <lambda_c36588078e9f5dfd39652860aa6b3aaf>,class <lambda_ec61778202f4f5fc7e7711acc23c3bca>& __ptr64,class <lambda_dc9d2797ccde5d239b4a0efae8ebd7db>,void (__cdecl*)(int32_t)>::operator()<class <lambda_c36588078e9f5dfd39652860aa6b3aaf>,class <lambda_ec61778202f4f5fc7e7711acc23c3bca>& __ptr64,class <lambda_dc9d2797ccde5d239b4a0efae8ebd7db> >(
        &arg_8, &arg_18, &arg_8, &arg_10);
}

int64_t _initp_misc_winsig(int64_t arg1)
{
    data_140017c00 = arg1;
    data_140017c08 = arg1;
    data_140017c10 = arg1;
    data_140017c18 = arg1;
}

int64_t raise(int32_t arg1)
{
    void** r13 = nullptr;
    int32_t arg_18 = 0;
    int64_t rsi;
    rsi = 1;
    char arg_8 = 1;
    int32_t rax;
    int64_t* rdi_1;
    
    if (arg1 != 2)
    {
        if (arg1 == 4)
        {
            label_140007f84:
            void** rax_1 = __acrt_getptd_noexit();
            r13 = rax_1;
            
            if (!rax_1)
                return 0xffffffff;
            
            void* rcx = *rax_1;
            void* rdx_1 = 0xc0 + rcx;
            
            while (true)
            {
                if (rcx == rdx_1)
                {
                    rcx = nullptr;
                    break;
                }
                
                if (*(rcx + 4) == arg1)
                    break;
                
                rcx += 0x10;
            }
            
            rax = rcx;
            
            if (!rax)
                goto label_140007fcd;
            
            rdi_1 = rcx + 8;
            rsi = 0;
            arg_8 = 0;
            goto label_14000802a;
        }
        
        if (arg1 == 6)
            goto label_140007feb;
        
        if (arg1 == 8 || arg1 == 0xb)
            goto label_140007f84;
        
        if (arg1 != 0xf && arg1 - 0x15 > 1)
        {
            label_140007fcd:
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            return 0xffffffff;
        }
    }
    
    label_140007feb:
    
    if (arg1 != 2)
    {
        if (arg1 == 6)
            rdi_1 = &data_140017c10;
        else if (arg1 == 0xf)
            rdi_1 = &data_140017c18;
        else if (arg1 == 0x15)
            rdi_1 = &data_140017c08;
        else if (arg1 == 0x16)
            rdi_1 = &data_140017c10;
        else
            rdi_1 = nullptr;
        
        goto label_14000802a;
    }
    
    rdi_1 = &data_140017c00;
    label_14000802a:
    int64_t arg_20 = 0;
    
    if (rsi)
        __vcrt_unlock(3);
    
    int64_t r12_1;
    
    if (!rsi)
        r12_1 = *rdi_1;
    else
    {
        uint64_t __security_cookie_1 = __security_cookie;
        r12_1 = RORQ(__security_cookie_1 ^ *rdi_1, __security_cookie_1 & 0x3f);
    }
    
    rax = r12_1 == 1;
    char arg_10 = rax;
    
    if (!rax)
    {
        if (!r12_1)
        {
            if (rsi)
                __vcrt_lock(r12_1 + 3);
            
            sub_140004198(3);
        }
        
        if (arg1 > 0xb || !TEST_BITD(0x910, arg1))
            goto label_1400080e1;
        
        int64_t rax_3 = r13[1];
        arg_20 = rax_3;
        int64_t var_48_1 = rax_3;
        r13[1] = 0;
        
        if (arg1 != 8)
            *rdi_1 = __security_cookie;
        else
        {
            int32_t rax_5 = sub_14000538c()[2];
            arg_18 = rax_5;
            int32_t var_58_1 = rax_5;
            sub_14000538c()[2] = 0x8c;
            label_1400080e1:
            
            if (arg1 != 8)
                *rdi_1 = __security_cookie;
            else
            {
                void* rax_7 = 0x30 + *r13;
                void* rcx_8 = 0x90 + rax_7;
                
                while (true)
                {
                    void* var_50_1 = rax_7;
                    
                    if (rax_7 == rcx_8)
                        break;
                    
                    *(rax_7 + 8) = 0;
                    rax_7 += 0x10;
                }
            }
        }
    }
    
    if (rsi)
        __vcrt_lock(3);
    
    if (!arg_10)
    {
        if (arg1 != 8)
            _guard_dispatch_icall_nop(arg1);
        else
        {
            sub_14000538c();
            _guard_dispatch_icall_nop(arg1);
        }
        
        if (arg1 <= 0xb && TEST_BITD(0x910, arg1))
        {
            r13[1] = arg_20;
            
            if (arg1 == 8)
                sub_14000538c()[2] = arg_18;
        }
    }
    
    return 0;
}

uint64_t _mbtowc_l(int16_t* arg1, char* arg2, int64_t arg3, int128_t* arg4)
{
    char* lpMultiByteStr = arg2;
    
    if (arg2 && arg3)
    {
        if (*arg2)
        {
            void* var_28;
            sub_140004c30(&var_28, arg4);
            void* var_20;
            int32_t rbx_1;
            
            if (*(var_20 + 0x138))
            {
                rbx_1 = 1;
                
                if (!sub_140009204(*lpMultiByteStr, &var_20))
                {
                    int32_t cchWideChar_1;
                    cchWideChar_1 = arg1;
                    
                    if (!MultiByteToWideChar(*(var_20 + 0xc), 
                        MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, lpMultiByteStr, 1, arg1, 
                        cchWideChar_1))
                    {
                        rbx_1 = -1;
                        *_errno() = 0x2a;
                    }
                }
                else
                {
                    void* rcx_2 = var_20;
                    int32_t cbMultiByte = *(rcx_2 + 8);
                    
                    if (cbMultiByte > 1 && arg3 >= cbMultiByte)
                    {
                        int32_t cchWideChar;
                        cchWideChar = arg1;
                        int32_t rax_4 = MultiByteToWideChar(*(rcx_2 + 0xc), 
                            MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, lpMultiByteStr, cbMultiByte, 
                            arg1, cchWideChar);
                        rcx_2 = var_20;
                        
                        if (rax_4 || (arg3 >= *(rcx_2 + 8) && lpMultiByteStr[1]))
                            rbx_1 = *(rcx_2 + 8);
                        else
                        {
                            rbx_1 = -1;
                            *_errno() = 0x2a;
                        }
                    }
                    else if (arg3 < *(rcx_2 + 8) || !lpMultiByteStr[1])
                    {
                        rbx_1 = -1;
                        *_errno() = 0x2a;
                    }
                    else
                        rbx_1 = *(rcx_2 + 8);
                }
            }
            else
            {
                if (arg1)
                    *arg1 = *lpMultiByteStr;
                
                rbx_1 = 1;
            }
            
            char var_10;
            
            if (var_10)
            {
                void* rcx_5 = var_28;
                *(rcx_5 + 0x3a8) &= 0xfffffffd;
            }
            
            return rbx_1;
        }
        
        if (arg1)
            *arg1 = 0;
    }
    
    return 0;
}

int64_t sub_14000830c(int16_t* arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return _mbtowc_l(arg1, arg2, arg3, nullptr);
}

uint64_t __acrt_update_locale_info(void* arg1, int64_t* arg2)
{
    uint64_t result = data_140017a38;
    
    if (*arg2 != result)
    {
        result = *(arg1 + 0x3a8);
        
        if (!(data_1400167a0 & result))
        {
            result = __acrt_update_thread_locale_data();
            *arg2 = result;
        }
    }
    
    return result;
}

uint64_t sub_140008348(void* arg1, int64_t* arg2)
{
    uint64_t result = data_1400173a0;
    
    if (*arg2 != result)
    {
        result = *(arg1 + 0x3a8);
        
        if (!(data_1400167a0 & result))
        {
            result = sub_1400064a8();
            *arg2 = result;
        }
    }
    
    return result;
}

uint64_t _fileno(void* arg1)
{
    if (arg1)
        return *(arg1 + 0x18);
    
    *_errno() = 0x16;
    _invalid_parameter_noinfo();
    return 0xffffffff;
}

int64_t __acrt_initialize_stdio()
{
    int32_t rax = data_140017c30;
    int64_t rbx = 0;
    int64_t i_1 = 3;
    
    if (!rax)
        rax = 0x200;
    else if (rax < 3)
        rax = 3;
    
    data_140017c30 = rax;
    data_140017c38 = _calloc_base(rax, 8);
    _free_base(0);
    
    if (!data_140017c38)
    {
        data_140017c30 = 3;
        data_140017c38 = _calloc_base(3, 8);
        _free_base(0);
        
        if (!data_140017c38)
            return 0xffffffff;
    }
    
    void** r14_1 = nullptr;
    void* rsi_1 = &data_1400167c8;
    void* rbp_1 = &data_1400167b0;
    int64_t i;
    
    do
    {
        __vcrt_InitializeCriticalSectionEx(rbp_1 + 0x30, 0xfa0, 0);
        *(r14_1 + data_140017c38) = rbp_1;
        
        if (*((&data_140017630)[rbx >> 6] + ((rbx & 0x3f) << 6) + 0x28) + 2 <= 2)
            *rsi_1 = 0xfffffffe;
        
        rbx += 1;
        rbp_1 += 0x58;
        r14_1 = &r14_1[1];
        rsi_1 += 0x58;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return 0;
}

int64_t __acrt_uninitialize_stdio()
{
    sub_1400091fc();
    sub_140009244();
    
    for (int64_t* i = nullptr; i != 0x18; i = &i[1])
    {
        __acrt_stdio_free_buffer_nolock(*(i + data_140017c38));
        DeleteCriticalSection(*(i + data_140017c38) + 0x30);
    }
    
    int64_t result = _free_base(data_140017c38);
    data_140017c38 = 0;
    return result;
}

int64_t sub_140008520(void* arg1)
{
    /* tailcall */
    return EnterCriticalSection(arg1 + 0x30);
}

int64_t sub_14000852c(void* arg1)
{
    /* tailcall */
    return LeaveCriticalSection(arg1 + 0x30);
}

void sub_140008540(int64_t arg1, char* arg2, int64_t arg3, int64_t arg4)
{
    if (arg2 > arg1)
    {
        char* rdi_1 = arg2;
        int64_t r12_1 = arg1 + arg3;
        
        do
        {
            int64_t rbx_1 = arg1;
            int64_t rsi_1 = r12_1;
            
            if (r12_1 <= rdi_1)
            {
                do
                {
                    if (arg4(rsi_1, rbx_1) > 0)
                        rbx_1 = rsi_1;
                    
                    rsi_1 += arg3;
                } while (rsi_1 <= rdi_1);
            }
            
            int64_t i_1 = arg3;
            char* rax = rdi_1;
            
            if (rbx_1 != rdi_1 && arg3)
            {
                char* rbx_2 = rbx_1 - rdi_1;
                int64_t i;
                
                do
                {
                    char rdx_1 = *(rbx_2 + rax);
                    *(rbx_2 + rax) = *rax;
                    *rax = rdx_1;
                    rax = &rax[1];
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
            }
            
            rdi_1 -= arg3;
        } while (rdi_1 > arg1);
    }
}

void* qsort(char* arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    void var_458;
    void* result = __security_cookie ^ &var_458;
    void* result_1 = result;
    char* r12 = arg1;
    
    if (arg1)
    {
        if (arg3 && arg4)
            goto label_140008655;
        
        *_errno() = 0x16;
        result = _invalid_parameter_noinfo();
    }
    else if (!arg2 && arg3 && arg4)
    {
        label_140008655:
        
        if (arg2 >= 2)
        {
            char* r15_3 = (arg2 - 1) * arg3 + arg1;
            int64_t r13_1 = 0;
            
            while (true)
            {
                int64_t var_438[0x3e];
                int64_t var_248[0x3e];
                
                if (COMBINE(0, r15_3 - r12) / arg3 + 1 > 8)
                {
                    char* rsi_4 = ((COMBINE(0, r15_3 - r12) / arg3 + 1) >> 1) * arg3 + r12;
                    
                    if (arg4(r12, rsi_4) > 0)
                    {
                        int64_t i_5 = arg3;
                        char* rdx_4 = rsi_4;
                        
                        if (r12 != rsi_4)
                        {
                            char* r9_2 = r12 - rsi_4;
                            int64_t i;
                            
                            do
                            {
                                char rcx_1 = *(r9_2 + rdx_4);
                                *(r9_2 + rdx_4) = *rdx_4;
                                *rdx_4 = rcx_1;
                                rdx_4 = &rdx_4[1];
                                i = i_5;
                                i_5 -= 1;
                            } while (i != 1);
                        }
                    }
                    
                    if (arg4(r12, r15_3) > 0)
                    {
                        int64_t i_6 = arg3;
                        char* rdx_6 = r15_3;
                        
                        if (r12 != r15_3)
                        {
                            void* r9_4 = r12 - r15_3;
                            int64_t i_1;
                            
                            do
                            {
                                char rcx_3 = *(r9_4 + rdx_6);
                                *(r9_4 + rdx_6) = *rdx_6;
                                *rdx_6 = rcx_3;
                                rdx_6 = &rdx_6[1];
                                i_1 = i_6;
                                i_6 -= 1;
                            } while (i_1 != 1);
                        }
                    }
                    
                    if (arg4(rsi_4, r15_3) > 0)
                    {
                        int64_t i_7 = arg3;
                        char* rdx_8 = r15_3;
                        
                        if (rsi_4 != r15_3)
                        {
                            void* r9_6 = rsi_4 - r15_3;
                            int64_t i_2;
                            
                            do
                            {
                                char rcx_5 = *(r9_6 + rdx_8);
                                *(r9_6 + rdx_8) = *rdx_8;
                                *rdx_8 = rcx_5;
                                rdx_8 = &rdx_8[1];
                                i_2 = i_7;
                                i_7 -= 1;
                            } while (i_2 != 1);
                        }
                    }
                    
                    char* rbx_1 = r12;
                    char* rdi_1 = r15_3;
                    int32_t i_3;
                    
                    while (true)
                    {
                        if (rsi_4 <= rbx_1)
                        {
                            label_1400087de:
                            
                            do
                            {
                                rbx_1 = &rbx_1[arg3];
                                
                                if (rbx_1 > r15_3)
                                    break;
                                
                                i_3 = arg4(rbx_1, rsi_4);
                            } while (i_3 <= 0);
                        }
                        else
                        {
                            do
                            {
                                rbx_1 = &rbx_1[arg3];
                                
                                if (rbx_1 >= rsi_4)
                                    goto label_1400087de;
                                
                                i_3 = arg4(rbx_1, rsi_4);
                            } while (i_3 <= 0);
                            
                            if (rsi_4 <= rbx_1)
                                goto label_1400087de;
                        }
                        
                        do
                        {
                            rdi_1 -= arg3;
                            
                            if (rdi_1 <= rsi_4)
                                break;
                            
                            i_3 = arg4(rdi_1, rsi_4);
                        } while (i_3 > 0);
                        
                        if (rdi_1 < rbx_1)
                            break;
                        
                        int64_t i_8 = arg3;
                        char* rdx_12 = rdi_1;
                        
                        if (rbx_1 != rdi_1)
                        {
                            char* r9_8 = rbx_1 - rdi_1;
                            int64_t i_4;
                            
                            do
                            {
                                char rcx_9 = *(r9_8 + rdx_12);
                                *(r9_8 + rdx_12) = *rdx_12;
                                *rdx_12 = rcx_9;
                                rdx_12 = &rdx_12[1];
                                i_4 = i_8;
                                i_8 -= 1;
                            } while (i_4 != 1);
                        }
                        
                        if (rsi_4 == rdi_1)
                            rsi_4 = rbx_1;
                    }
                    
                    void* rdi_2 = &rdi_1[arg3];
                    
                    if (rsi_4 >= rdi_2)
                    {
                        label_14000887b:
                        
                        do
                        {
                            rdi_2 -= arg3;
                            
                            if (rdi_2 <= r12)
                                break;
                            
                            i_3 = arg4(rdi_2, rsi_4);
                        } while (!i_3);
                    }
                    else
                    {
                        do
                        {
                            rdi_2 -= arg3;
                            
                            if (rdi_2 <= rsi_4)
                                goto label_14000887b;
                            
                            i_3 = arg4(rdi_2, rsi_4);
                        } while (!i_3);
                        
                        if (rsi_4 >= rdi_2)
                            goto label_14000887b;
                    }
                    
                    result = rdi_2 - r12;
                    
                    if (result < r15_3 - rbx_1)
                    {
                        if (rbx_1 < r15_3)
                        {
                            var_438[r13_1] = rbx_1;
                            var_248[r13_1] = r15_3;
                            r13_1 += 1;
                        }
                        
                        if (r12 < rdi_2)
                        {
                            r15_3 = rdi_2;
                            continue;
                        }
                    }
                    else
                    {
                        if (r12 < rdi_2)
                        {
                            var_438[r13_1] = r12;
                            var_248[r13_1] = rdi_2;
                            r13_1 += 1;
                        }
                        
                        if (rbx_1 < r15_3)
                        {
                            r12 = rbx_1;
                            continue;
                        }
                    }
                }
                else
                    result = sub_140008540(r12, r15_3, arg3, arg4);
                
                int64_t temp3_1 = r13_1;
                r13_1 -= 1;
                
                if (temp3_1 - 1 < 0)
                    break;
                
                r12 = var_438[r13_1];
                r15_3 = var_248[r13_1];
            }
        }
    }
    else
    {
        *_errno() = 0x16;
        result = _invalid_parameter_noinfo();
    }
    
    __security_check_cookie(result_1 ^ &var_458);
    return result;
}

uint64_t initialize_multibyte()
{
    int32_t rcx;
    rcx = !__acrt_initialize_multibyte();
    return rcx;
}

uint64_t __acrt_LCMapStringA_stat(int64_t* arg1, int64_t arg2, int32_t arg3, char* arg4, int32_t arg5, int64_t arg6, int32_t arg7, uint32_t arg8, int32_t arg9)
{
    int64_t __saved_rbp_1;
    int64_t __saved_rbp = __saved_rbp_1;
    int64_t __saved_r12_1;
    int64_t __saved_r12 = __saved_r12_1;
    int64_t __saved_r13_1;
    int64_t __saved_r13 = __saved_r13_1;
    int64_t __saved_r14_1;
    int64_t __saved_r14 = __saved_r14_1;
    int64_t __saved_r15_1;
    int64_t __saved_r15 = __saved_r15_1;
    void var_88;
    void* rsp_1 = &var_88;
    int64_t __saved_rbx_1;
    int64_t __saved_rbx = __saved_rbx_1;
    int64_t __saved_rsi_1;
    int64_t __saved_rsi = __saved_rsi_1;
    int64_t __saved_rdi_1;
    int64_t __saved_rdi = __saved_rdi_1;
    int64_t var_38;
    int64_t rax_1 = __security_cookie ^ &var_38;
    int64_t rbx = arg5;
    var_38 = arg2;
    
    if (rbx > 0)
    {
        arg2 = rbx;
        int32_t rax_2 = sub_140009338(arg4, arg2);
        bool cond:0_1 = rax_2 < rbx;
        rbx = rax_2 + 1;
        
        if (!cond:0_1)
            rbx = rax_2;
    }
    
    uint32_t CodePage = arg8;
    
    if (!CodePage)
        CodePage = *(*arg1 + 0xc);
    
    int32_t temp0 = arg9;
    arg9 = -(arg9);
    uint64_t result = MultiByteToWideChar(CodePage, ((arg2 - arg2) & 8) + 1, arg4, rbx, nullptr, 0);
    int64_t r12 = result;
    
    if (result)
    {
        int64_t rdx_4 = r12 * 2;
        uint64_t rax_4 = result - result;
        void* rsi;
        int64_t rdi_1;
        
        if (!((rdx_4 + 0x10) & rax_4))
        {
            rsi = nullptr;
            label_140008a63:
            
            if (!rsi)
                rdi_1 = 0;
            else
            {
                *(rsp_1 + 0x28) = r12;
                *(rsp_1 + 0x20) = rsi;
                
                if (!MultiByteToWideChar(/* nop */, /* nop */, /* nop */, /* nop */))
                    rdi_1 = 0;
                else
                {
                    __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                    int64_t r15_1 = var_38;
                    *(rsp_1 + 0x28) = 0;
                    *(rsp_1 + 0x20) = 0;
                    int64_t rax_12 = sub_140007b70(r15_1, arg3, rsi, r12);
                    rdi_1 = rax_12;
                    
                    if (!rax_12)
                        rdi_1 = 0;
                    else if (!(0x400 & arg3))
                    {
                        int64_t rdx_9 = rdi_1 * 2;
                        int64_t rax_16 = rax_12 - rax_12;
                        void* rbx_1;
                        
                        if (!((rdx_9 + 0x10) & rax_16))
                        {
                            rbx_1 = nullptr;
                            label_140008bb9:
                            
                            if (!rbx_1)
                                rdi_1 = 0;
                            else
                            {
                                __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                                *(rsp_1 + 0x28) = rdi_1;
                                *(rsp_1 + 0x20) = rbx_1;
                                int32_t rax_23 = sub_140007b70(r15_1, arg3, rsi, r12);
                                int32_t rax_25;
                                
                                if (rax_23)
                                {
                                    *(rsp_1 + 0x38) = 0;
                                    *(rsp_1 + 0x30) = 0;
                                    
                                    if (arg7)
                                    {
                                        *(rsp_1 + 0x28) = arg7;
                                        *(rsp_1 + 0x20) = arg6;
                                    }
                                    else
                                    {
                                        *(rsp_1 + 0x28) = 0;
                                        *(rsp_1 + 0x20) = 0;
                                    }
                                    
                                    rax_25 = WideCharToMultiByte();
                                    rdi_1 = rax_25;
                                }
                                
                                if (rax_23 && rax_25)
                                {
                                    if (*(rbx_1 - 0x10) == 0xdddd)
                                        _free_base(rbx_1 - 0x10);
                                }
                                else if (*(rbx_1 - 0x10) != 0xdddd)
                                    rdi_1 = 0;
                                else
                                {
                                    _free_base(rbx_1 - 0x10);
                                    rdi_1 = 0;
                                }
                            }
                        }
                        else
                        {
                            if (((rax_16 - rax_16) & (rdx_9 + 0x10)) > 0x400)
                            {
                                void* rax_22 =
                                    sub_140004aa0((rdx_9 + 0x10 - (rdx_9 + 0x10)) & (rdx_9 + 0x10));
                                rbx_1 = rax_22;
                                
                                if (!rax_22)
                                    goto label_140008bb9;
                                
                                *rax_22 = 0xdddd;
                                label_140008bb1:
                                rbx_1 += 0x10;
                                goto label_140008bb9;
                            }
                            
                            int64_t rcx_14 = (rdx_9 + 0x10 - (rdx_9 + 0x10)) & (rdx_9 + 0x10);
                            int64_t rax_20 = rcx_14 + 0xf;
                            
                            if (rax_20 <= rcx_14)
                                rax_20 = 0xffffffffffffff0;
                            
                            int64_t rax_21 = rax_20 & 0xfffffffffffffff0;
                            __chkstk(rax_21);
                            rsp_1 -= rax_21;
                            rbx_1 = rsp_1 + 0x50;
                            
                            if (rbx_1)
                            {
                                *rbx_1 = 0xcccc;
                                goto label_140008bb1;
                            }
                            
                            rdi_1 = 0;
                        }
                    }
                    else if (arg7)
                    {
                        if (rdi_1 > arg7)
                            rdi_1 = 0;
                        else
                        {
                            __builtin_memset(rsp_1 + 0x30, 0, 0x18);
                            *(rsp_1 + 0x28) = arg7;
                            *(rsp_1 + 0x20) = arg6;
                            int32_t rax_15 = sub_140007b70(r15_1, arg3, rsi, r12);
                            rdi_1 = rax_15;
                            
                            if (!rax_15)
                                rdi_1 = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (((rax_4 - rax_4) & (rdx_4 + 0x10)) > 0x400)
            {
                void* rax_10;
                int512_t zmm0;
                rax_10 = sub_140004aa0((rdx_4 + 0x10 - (rdx_4 + 0x10)) & (rdx_4 + 0x10));
                rsi = rax_10;
                
                if (!rax_10)
                    goto label_140008a63;
                
                *rax_10 = 0xdddd;
                label_140008a5b:
                rsi += 0x10;
                goto label_140008a63;
            }
            
            int64_t rcx_5 = (rdx_4 + 0x10 - (rdx_4 + 0x10)) & (rdx_4 + 0x10);
            int64_t rax_8 = rcx_5 + 0xf;
            
            if (rax_8 <= rcx_5)
                rax_8 = 0xffffffffffffff0;
            
            int64_t rax_9 = rax_8 & 0xfffffffffffffff0;
            __chkstk(rax_9);
            rsp_1 = &var_88 - rax_9;
            rsi = rsp_1 + 0x50;
            
            if (rsi)
            {
                *rsi = 0xcccc;
                goto label_140008a5b;
            }
            
            rdi_1 = 0;
        }
        
        if (rsi && *(rsi - 0x10) == 0xdddd)
            _free_base(rsi - 0x10);
        
        result = rdi_1;
    }
    
    __security_check_cookie(rax_1 ^ &var_38);
    return result;
}

uint64_t sub_140008c94(int128_t* arg1, int64_t arg2, int32_t arg3, char* arg4, int32_t arg5, int64_t arg6, int32_t arg7, uint32_t arg8, int32_t arg9)
{
    void* var_28;
    sub_140004c30(&var_28, arg1);
    void var_20;
    uint64_t result =
        __acrt_LCMapStringA_stat(&var_20, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    char var_10;
    
    if (var_10)
    {
        void* rcx_2 = var_28;
        *(rcx_2 + 0x3a8) &= 0xfffffffd;
    }
    
    return result;
}

uint64_t sub_140008d2c(int64_t arg1)
{
    int32_t r10 = 0;
    int32_t r11 = 0xe3;
    
    do
    {
        int32_t temp0_1;
        int32_t temp1_1;
        temp0_1 = HIGHD(r11 + r10);
        temp1_1 = LOWD(r11 + r10);
        int64_t rbx_1 = 0x55;
        int64_t r8_1 = (temp1_1 - temp0_1) >> 1;
        int16_t* r9_1 = (&data_14000ed20)[r8_1 * 2];
        int16_t* rdi_2 = arg1 - r9_1;
        int16_t rcx_3;
        int16_t rdx_2;
        
        do
        {
            rdx_2 = *(rdi_2 + r9_1);
            
            if (rdx_2 - 0x41 <= 0x19)
                rdx_2 += 0x20;
            
            rcx_3 = *r9_1;
            
            if (rcx_3 - 0x41 <= 0x19)
                rcx_3 += 0x20;
            
            r9_1 = &r9_1[1];
            int64_t temp2_1 = rbx_1;
            rbx_1 -= 1;
            
            if (temp2_1 == 1)
                break;
            
            if (!rdx_2)
                break;
        } while (rdx_2 == rcx_3);
        
        uint32_t rax_6 = rcx_3;
        uint32_t rcx_4 = rdx_2;
        
        if (rcx_4 == rax_6)
            return *(r8_1 * 0x10 + 0x14000ed28);
        
        if (rcx_4 - rax_6 >= 0)
            r10 = r8_1 + 1;
        else
            r11 = r8_1 - 1;
    } while (r10 <= r11);
    
    return 0xffffffff;
}

uint64_t sub_140008df4(int64_t arg1)
{
    if (arg1)
    {
        int32_t rax_1 = sub_140008d2c(arg1);
        
        if (rax_1 >= 0)
        {
            int64_t rax_2 = rax_1;
            
            if (rax_2 < 0xe4)
                return *(&data_1400105c0 + rax_2 * 0x10);
        }
    }
    
    return 0;
}

int64_t j__msize_base(int64_t arg1)
{
    /* tailcall */
    return _msize_base(arg1);
}

int64_t _msize_base(int64_t arg1)
{
    if (arg1)
        /* tailcall */
        return HeapSize(data_140017bf8, HEAP_NONE, arg1);
    
    *_errno() = 0x16;
    _invalid_parameter_noinfo();
    return -1;
}

int64_t _realloc_base(int64_t arg1, uint64_t arg2)
{
    if (!arg1)
        return sub_140004aa0(arg2);
    
    if (arg2)
    {
        if (arg2 <= -0x20)
        {
            uint64_t dwBytes = arg2;
            int64_t lpMem = arg1;
            
            while (true)
            {
                int64_t result = HeapReAlloc(data_140017bf8, HEAP_NONE, lpMem, dwBytes);
                
                if (result)
                    return result;
                
                if (!sub_14000434c())
                    break;
                
                if (!sub_140004390(arg2))
                    break;
                
                dwBytes = arg2;
                lpMem = arg1;
            }
        }
        
        *_errno() = 0xc;
    }
    else
        _free_base(arg1);
    
    return 0;
}

uint64_t _isatty(int32_t arg1)
{
    if (arg1 != 0xfffffffe)
    {
        if (arg1 >= 0 && arg1 < data_140017a30)
        {
            int64_t rcx = arg1;
            return *((&data_140017630)[rcx >> 6] + ((rcx & 0x3f) << 6) + 0x38) & 0x40;
        }
        
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    else
        *_errno() = 9;
    
    return 0;
}

int64_t sub_140008f50(int64_t arg1, int64_t* arg2, int64_t* arg3, int64_t* arg4)
{
    int64_t* arg_20 = arg4;
    sub_140008520(*arg2);
    int32_t* rdx = arg3[1];
    void* rax_1 = **arg3;
    
    if (rax_1)
    {
        int32_t rcx_1 = *(rax_1 + 0x14);
        
        if (rcx_1 >> 0xd & 1)
        {
            if (((rcx_1 & 3) != 2 || !(rcx_1 & 0xc0)) && !TEST_BITD(rcx_1, 0xb))
                *rdx += 1;
            else if (*arg3[2] || *(**arg3 + 0x14) >> 1 & 1)
            {
                if (_fflush_nolock(**arg3) == 0xffffffff)
                    *arg3[3] = 0xffffffff;
                else
                {
                    int32_t* rax_11 = arg3[1];
                    *rax_11 += 1;
                }
            }
        }
    }
    
    return sub_14000852c(*arg4);
}

int64_t __crt_seh_guarded_call<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752>,void>::operator()<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __vcrt_unlock(*arg2);
    int64_t* rbx = data_140017c38;
    void* r14 = &rbx[data_140017c30];
    
    while (true)
    {
        int64_t* var_40_1 = rbx;
        
        if (rbx == r14)
            break;
        
        void* rax_1 = *rbx;
        void* var_58 = rax_1;
        int32_t* rdx = *arg3;
        
        if (rax_1)
        {
            int32_t rcx_1 = *(rax_1 + 0x14);
            
            if (rcx_1 >> 0xd & 1)
            {
                if ((rcx_1 & 3) != 2)
                {
                    if (TEST_BITD(rcx_1, 0xb))
                        goto label_14000905f;
                    
                    *rdx += 1;
                }
                else if (rcx_1 & 0xc0 || TEST_BITD(rcx_1, 0xb))
                {
                    label_14000905f:
                    int64_t rdx_1 = arg3[2];
                    int64_t rcx_2 = arg3[1];
                    int64_t rax_5 = *arg3;
                    void** var_38 = &var_58;
                    int64_t var_30_1 = rax_5;
                    int64_t var_28_1 = rcx_2;
                    int64_t var_20_1 = rdx_1;
                    void* rax_6 = var_58;
                    void* var_50 = rax_6;
                    void* var_48 = rax_6;
                    void arg_10;
                    sub_140008f50(&arg_10, &var_48, &var_38, &var_50);
                }
                else
                    *rdx += 1;
            }
        }
        
        rbx = &rbx[1];
    }
    
    return __vcrt_lock(*arg4);
}

uint64_t common_flush_all(char arg1)
{
    char arg_8 = arg1;
    int32_t arg_20 = 0;
    int32_t arg_18 = 0;
    int32_t* var_20 = &arg_20;
    char* var_18 = &arg_8;
    int32_t* var_10 = &arg_18;
    int32_t var_28 = 8;
    int32_t var_24 = 8;
    void arg_10;
    __crt_seh_guarded_call<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752>,void>::operator()<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752> >(
        &arg_10, &var_24, &var_20, &var_28);
    
    if (arg_8)
        return arg_20;
    
    return arg_18;
}

int64_t __acrt_stdio_flush_nolock(int32_t* arg1)
{
    char rcx = arg1[5];
    
    if ((rcx & 3) == 2 && rcx & 0xc0)
    {
        int32_t rdi_2 = *arg1 - arg1[2];
        arg1[4] = 0;
        int16_t* rsi_1 = *(arg1 + 8);
        *arg1 = rsi_1;
        
        if (rdi_2 > 0)
        {
            if (rdi_2 != sub_140009a2c(_fileno(arg1), rsi_1, rdi_2))
            {
                arg1[5] |= 0x10;
                return 0xffffffff;
            }
            
            if (arg1[5] >> 2 & 1)
                arg1[5] &= 0xfffffffd;
        }
    }
    
    return 0;
}

int64_t _fflush_nolock(int32_t* arg1)
{
    if (!arg1)
        /* tailcall */
        return common_flush_all(arg1);
    
    if (!__acrt_stdio_flush_nolock(arg1))
    {
        int32_t rax_5;
        
        if (arg1[5] >> 0xb & 1)
            rax_5 = _commit(_fileno(arg1));
        
        if (!(arg1[5] >> 0xb & 1) || !rax_5)
            return 0;
    }
    
    return 0xffffffff;
}

int64_t sub_1400091fc()
{
    /* tailcall */
    return common_flush_all(1);
}

uint64_t sub_140009204(char arg1, int128_t* arg2)
{
    void* var_28;
    sub_140004c30(&var_28, arg2);
    int64_t* var_20;
    uint64_t result = *(*var_20 + (arg1 << 1)) & 0x8000;
    char var_10;
    
    if (var_10)
    {
        void* rcx_2 = var_28;
        *(rcx_2 + 0x3a8) &= 0xfffffffd;
    }
    
    return result;
}

uint64_t sub_140009244()
{
    int32_t var_18 = 0;
    __vcrt_unlock(8);
    int32_t rbx = 3;
    
    while (true)
    {
        int32_t var_14_1 = rbx;
        
        if (rbx == data_140017c30)
            break;
        
        int64_t rdi_1 = rbx;
        void* rax_2 = *(data_140017c38 + (rdi_1 << 3));
        
        if (rax_2)
        {
            if (*(rax_2 + 0x14) >> 0xd & 1
                    && sub_14000a4f4(*(data_140017c38 + (rdi_1 << 3))) != 0xffffffff)
                var_18 += 1;
            
            DeleteCriticalSection(*(data_140017c38 + (rdi_1 << 3)) + 0x30);
            _free_base(*(data_140017c38 + (rdi_1 << 3)));
            *(data_140017c38 + (rdi_1 << 3)) = 0;
        }
        
        rbx += 1;
    }
    
    __vcrt_lock(8);
    return var_18;
}

uint8_t __acrt_stdio_free_buffer_nolock(void* arg1)
{
    uint8_t result = *(arg1 + 0x14) >> 0xd;
    
    if (result & 1)
    {
        result = *(arg1 + 0x14) >> 6;
        
        if (result & 1)
        {
            _free_base(*(arg1 + 8));
            *(arg1 + 0x14) &= 0xfffffebf;
            result = 0;
            __builtin_memset(arg1, 0, 0x14);
        }
    }
    
    return result;
}

char* sub_140009338(char* arg1, int64_t arg2)
{
    char* result = nullptr;
    
    if (*arg1)
    {
        while (result != arg2)
        {
            result = &result[1];
            
            if (!*(result + arg1))
                break;
        }
    }
    
    return result;
}

uint64_t __crt_seh_guarded_call<class <lambda_b521505b218e5242e90febf6bfebc422>,class <lambda_6978c1fb23f02e42e1d9e99668cc68aa>& __ptr64,class <lambda_314360699dd331753a4119843814e9a7>,int32_t>::operator()<class <lambda_b521505b218e5242e90febf6bfebc422>,class <lambda_6978c1fb23f02e42e1d9e99668cc68aa>& __ptr64,class <lambda_314360699dd331753a4119843814e9a7> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __acrt_lowio_unlock_fh(*arg2);
    int64_t rcx_1 = **arg3;
    int32_t rbx_1;
    
    if (!(*((&data_140017630)[rcx_1 >> 6] + ((rcx_1 & 0x3f) << 6) + 0x38) & 1))
    {
        *_errno() = 9;
        rbx_1 = -1;
    }
    else
    {
        rbx_1 = 0;
        
        if (!FlushFileBuffers(sub_140006bb0(rcx_1)))
        {
            void* rax_6 = __doserrno();
            *rax_6 = GetLastError();
            *_errno() = 9;
            rbx_1 = -1;
        }
    }
    
    sub_140006ad0(*arg4);
    return rbx_1;
}

uint64_t _commit(int32_t arg1)
{
    int32_t arg_8 = arg1;
    int64_t rdx = arg1;
    
    if (rdx != 0xfffffffe)
    {
        if (arg1 >= 0 && rdx < data_140017a30
            && *((&data_140017630)[rdx >> 6] + ((rdx & 0x3f) << 6) + 0x38) & 1)
        {
            int32_t arg_18 = rdx;
            int32_t arg_20 = rdx;
            int32_t* var_18 = &arg_8;
            void arg_10;
            return __crt_seh_guarded_call<class <lambda_b521505b218e5242e90febf6bfebc422>,class <lambda_6978c1fb23f02e42e1d9e99668cc68aa>& __ptr64,class <lambda_314360699dd331753a4119843814e9a7>,int32_t>::operator()<class <lambda_b521505b218e5242e90febf6bfebc422>,class <lambda_6978c1fb23f02e42e1d9e99668cc68aa>& __ptr64,class <lambda_314360699dd331753a4119843814e9a7> >(
                &arg_10, &arg_20, &var_18, &arg_18);
        }
        
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    else
        *_errno() = 9;
    
    return 0xffffffff;
}

int32_t* sub_140009470(int32_t* arg1, int32_t arg2, char* arg3, int32_t arg4)
{
    void var_b8;
    int64_t rax_1 = __security_cookie ^ &var_b8;
    int64_t rsi = arg2;
    int64_t r12_1 = rsi >> 6;
    uint64_t rsi_2 = (rsi & 0x3f) << 6;
    int32_t var_60 = arg3;
    void* r13_1 = &arg3[arg4];
    HANDLE hFile = *((&data_140017630)[r12_1] + rsi_2 + 0x28);
    uint32_t CodePage_1 = GetConsoleCP();
    *arg1 = 0;
    char* rdi = arg3;
    uint32_t CodePage = CodePage_1;
    *(arg1 + 4) = 0;
    
    if (arg3 < r13_1)
    {
        void* r14_1 = &arg3[1];
        
        while (true)
        {
            uint8_t buffer_1 = *rdi;
            int64_t rdx = (&data_140017630)[r12_1];
            wchar16 wideCharStr = 0;
            uint8_t buffer = buffer_1;
            char rcx = *(rdx + rsi_2 + 0x3d);
            char* rdx_1;
            int64_t r8;
            
            if (!(rcx & 4))
            {
                if (!(*(___lc_codepage_func() + (*rdi << 1)) & 0x8000))
                {
                    r8 = 1;
                    rdx_1 = rdi;
                    goto label_14000957b;
                }
                
                if (r14_1 >= r13_1)
                {
                    int64_t rax_4;
                    rax_4 = *rdi;
                    *((&data_140017630)[r12_1] + rsi_2 + 0x3e) = rax_4;
                    int64_t rax_12 = (&data_140017630)[r12_1];
                    *(rax_12 + rsi_2 + 0x3d) |= 4;
                    arg1[1] += 1;
                    break;
                }
                
                if (sub_14000830c(&wideCharStr, rdi, 2) == 0xffffffff)
                    break;
                
                rdi = &rdi[1];
                r14_1 += 1;
            }
            else
            {
                char rax_3 = *(rdx + rsi_2 + 0x3e);
                *(rdx + rsi_2 + 0x3d) = rcx & 0xfb;
                char var_58;
                rdx_1 = &var_58;
                uint8_t buffer_2 = buffer_1;
                r8 = 2;
                var_58 = rax_3;
                label_14000957b:
                
                if (sub_14000830c(&wideCharStr, rdx_1, r8) == 0xffffffff)
                    break;
            }
            rdi = &rdi[1];
            r14_1 += 1;
            uint8_t var_50;
            int32_t nNumberOfBytesToWrite =
                WideCharToMultiByte(CodePage, 0, &wideCharStr, 1, &var_50, 5, nullptr, nullptr);
            
            if (!nNumberOfBytesToWrite)
                break;
            
            uint32_t numberOfBytesWritten;
            
            if (WriteFile(hFile, &var_50, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                arg1[1] = arg1[2] - var_60 + rdi;
                
                if (numberOfBytesWritten < nNumberOfBytesToWrite)
                    break;
                
                if (buffer != 0xa)
                {
                    label_140009638:
                    
                    if (rdi >= r13_1)
                        break;
                    
                    CodePage = CodePage_1;
                    continue;
                }
                else
                {
                    buffer = 0xd;
                    
                    if (WriteFile(hFile, &buffer, 1, &numberOfBytesWritten, nullptr))
                    {
                        if (numberOfBytesWritten < 1)
                            break;
                        
                        arg1[2] += 1;
                        arg1[1] += 1;
                        goto label_140009638;
                    }
                }
            }
            
            *arg1 = GetLastError();
            break;
        }
    }
    
    __security_check_cookie(rax_1 ^ &var_b8);
    return arg1;
}

int32_t* sub_140009698(int32_t* arg1, int32_t arg2, char* arg3, int32_t arg4)
{
    __chkstk(0x1450);
    void var_1468;
    int64_t rax_1 = __security_cookie ^ &var_1468;
    int64_t r10 = arg2;
    void* rbp_1 = &arg3[arg4];
    char* rsi = arg3;
    HANDLE hFile = *((&data_140017630)[r10 >> 6] + ((r10 & 0x3f) << 6) + 0x28);
    *arg1 = 0;
    *(arg1 + 4) = 0;
    
    if (arg3 < rbp_1)
    {
        do
        {
            uint8_t buffer[0x13ff];
            uint8_t (* rbx_1)[0x13ff] = &buffer;
            uint32_t rax_5;
            
            while (rsi < rbp_1)
            {
                rax_5 = *rsi;
                rsi = &rsi[1];
                
                if (rax_5 == 0xa)
                {
                    arg1[2] += 1;
                    *rbx_1 = 0xd;
                    rbx_1 = &(*rbx_1)[1];
                }
                
                *rbx_1 = rax_5;
                rbx_1 = &(*rbx_1)[1];
                void var_29;
                
                if (rbx_1 >= &var_29)
                    break;
            }
            
            uint32_t nNumberOfBytesToWrite = rbx_1 - &buffer;
            uint32_t numberOfBytesWritten[0x4];
            
            if (!WriteFile(hFile, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                *arg1 = GetLastError();
                break;
            }
            
            rax_5 = numberOfBytesWritten[0];
            arg1[1] += rax_5;
            
            if (rax_5 < nNumberOfBytesToWrite)
                break;
        } while (rsi < rbp_1);
    }
    
    __security_check_cookie(rax_1 ^ &var_1468);
    return arg1;
}

int32_t* write_text_utf16le_nolock(int32_t* arg1, int32_t arg2, int16_t* arg3, int32_t arg4)
{
    __chkstk(0x1450);
    void var_1468;
    int64_t rax_1 = __security_cookie ^ &var_1468;
    int64_t r10 = arg2;
    void* rbp_1 = arg4 + arg3;
    int16_t* rsi = arg3;
    HANDLE hFile = *((&data_140017630)[r10 >> 6] + ((r10 & 0x3f) << 6) + 0x28);
    *arg1 = 0;
    *(arg1 + 4) = 0;
    
    if (arg3 < rbp_1)
    {
        do
        {
            uint8_t buffer[0x13fe];
            uint8_t (* rbx_1)[0x13fe] = &buffer;
            
            while (rsi < rbp_1)
            {
                int16_t rax_5 = *rsi;
                rsi = &rsi[1];
                
                if (rax_5 == 0xa)
                {
                    arg1[2] += 2;
                    *rbx_1 = 0xd;
                    rbx_1 = &(*rbx_1)[2];
                }
                
                *rbx_1 = rax_5;
                rbx_1 = &(*rbx_1)[2];
                void var_2a;
                
                if (rbx_1 >= &var_2a)
                    break;
            }
            
            int32_t nNumberOfBytesToWrite = ((rbx_1 - &buffer) >> 1) * 2;
            uint32_t numberOfBytesWritten[0x4];
            
            if (!WriteFile(hFile, &buffer, nNumberOfBytesToWrite, &numberOfBytesWritten, nullptr))
            {
                *arg1 = GetLastError();
                break;
            }
            
            uint32_t rax_7 = numberOfBytesWritten[0];
            arg1[1] += rax_7;
            
            if (rax_7 < nNumberOfBytesToWrite)
                break;
        } while (rsi < rbp_1);
    }
    
    __security_check_cookie(rax_1 ^ &var_1468);
    return arg1;
}

int32_t* write_text_utf8_nolock(int32_t* arg1, int32_t arg2, int16_t* arg3, int32_t arg4)
{
    __chkstk(0x1470);
    void var_1498;
    int64_t rax_1 = __security_cookie ^ &var_1498;
    int64_t r10 = arg2;
    void* r14_1 = arg4 + arg3;
    int16_t* rdi = arg3;
    HANDLE hFile = *((&data_140017630)[r10 >> 6] + ((r10 & 0x3f) << 6) + 0x28);
    *arg1 = 0;
    *(arg1 + 4) = 0;
    
    for (bool cond:0 = arg3 >= r14_1; !cond:0; cond:0 = rdi >= r14_1)
    {
        wchar16 wideCharStr[0x354];
        wchar16 (* rax_5)[0x354] = &wideCharStr;
        
        while (rdi < r14_1)
        {
            int16_t rcx = *rdi;
            rdi = &rdi[1];
            
            if (rcx == 0xa)
            {
                *rax_5 = 0xd;
                rax_5 = &(*rax_5)[1];
            }
            
            *rax_5 = rcx;
            rax_5 = &(*rax_5)[1];
            void var_da0;
            
            if (rax_5 >= &var_da0)
                break;
        }
        
        void multiByteStr;
        int32_t rax_8 = WideCharToMultiByte(0xfde9, 0, &wideCharStr, (rax_5 - &wideCharStr) >> 1, 
            &multiByteStr, 0xd55, nullptr, nullptr);
        
        if (!rax_8)
        {
            label_1400099f9:
            *arg1 = GetLastError();
            break;
        }
        
        int32_t rsi_1 = 0;
        
        if (rax_8)
        {
            do
            {
                uint32_t numberOfBytesWritten[0x4];
                
                if (!WriteFile(hFile, &multiByteStr + rsi_1, rax_8 - rsi_1, &numberOfBytesWritten, 
                        nullptr))
                    goto label_1400099f9;
                
                rsi_1 += numberOfBytesWritten[0];
            } while (rsi_1 < rax_8);
        }
        
        arg1[1] = rdi - arg3;
    }
    
    __security_check_cookie(rax_1 ^ &var_1498);
    return arg1;
}

uint64_t sub_140009a2c(int32_t arg1, int16_t* arg2, int32_t arg3)
{
    int32_t arg_8 = arg1;
    int64_t rbx = arg1;
    
    if (rbx != 0xfffffffe)
    {
        if (arg1 >= 0 && rbx < data_140017a30)
        {
            int64_t r14_2 = rbx >> 6;
            uint64_t rsi_3 = (rbx & 0x3f) << 6;
            
            if (*((&data_140017630)[r14_2] + rsi_3 + 0x38) & 1)
            {
                __acrt_lowio_unlock_fh(rbx);
                int32_t rdi_1 = -1;
                
                if (*((&data_140017630)[r14_2] + rsi_3 + 0x38) & 1)
                    rdi_1 = _write_nolock(rbx, arg2, arg3);
                else
                {
                    *_errno() = 9;
                    *__doserrno() = 0;
                }
                
                sub_140006ad0(rbx);
                return rdi_1;
            }
        }
        
        *__doserrno() = 0;
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    else
    {
        *__doserrno() = 0;
        *_errno() = 9;
    }
    
    return 0xffffffff;
}

uint64_t _write_nolock(int32_t arg1, int16_t* arg2, int32_t arg3)
{
    uint64_t rsi = arg3;
    int64_t r15 = arg1;
    
    if (arg3)
    {
        int64_t rcx;
        int64_t rbx;
        int64_t r12_2;
        uint64_t r14_3;
        
        if (arg2)
        {
            r12_2 = r15 >> 6;
            r14_3 = (r15 & 0x3f) << 6;
            rcx = (&data_140017630)[r12_2];
            rbx = *(rcx + r14_3 + 0x39);
        }
        
        if (!arg2 || (rbx - 1 <= 1 && !(~rsi & 1)))
        {
            *__doserrno() = 0;
            *_errno() = 0x16;
            _invalid_parameter_noinfo();
            return 0xffffffff;
        }
        
        if (*(rcx + r14_3 + 0x38) & 0x20)
            j_common_lseek_nolock<int64_t>(r15, 0, FILE_END);
        
        int32_t var_58_1 = 0;
        int64_t var_54_1 = 0;
        int32_t rbx_1;
        enum WIN32_ERROR var_68;
        int64_t numberOfBytesWritten;
        int32_t* rax_14;
        
        if (!_isatty(r15) || !(*((&data_140017630)[r12_2] + r14_3 + 0x38) & 0x80))
        {
            label_140009ce4:
            int64_t rcx_8 = (&data_140017630)[r12_2];
            
            if (!(*(rcx_8 + r14_3 + 0x38) & 0x80))
            {
                HANDLE hFile = *(rcx_8 + r14_3 + 0x28);
                var_68 = NO_ERROR;
                numberOfBytesWritten = 0;
                
                if (!WriteFile(hFile, arg2, rsi, &numberOfBytesWritten, nullptr))
                    var_68 = GetLastError();
                
                rbx_1 = *numberOfBytesWritten[4];
                var_58_1 = var_68;
            }
            else
            {
                int32_t rcx_9 = rbx;
                
                if (!rbx)
                {
                    rax_14 = sub_140009698(&var_68, r15, arg2, rsi);
                    label_140009cd1:
                    rbx_1 = rax_14[2];
                    var_58_1 = *rax_14;
                }
                else
                {
                    if (rcx_9 == 1)
                    {
                        rax_14 = write_text_utf8_nolock(&var_68, r15, arg2, rsi);
                        goto label_140009cd1;
                    }
                    
                    if (rcx_9 == 2)
                    {
                        rax_14 = write_text_utf16le_nolock(&var_68, r15, arg2, rsi);
                        goto label_140009cd1;
                    }
                    
                    rbx_1 = *var_54_1[4];
                }
            }
        }
        else
        {
            if (!*(sub_14000538c()[0x12] + 0x138) && !*((&data_140017630)[r12_2] + r14_3 + 0x39))
                goto label_140009ce4;
            
            enum CONSOLE_MODE mode;
            
            if (!GetConsoleMode(*((&data_140017630)[r12_2] + r14_3 + 0x28), &mode))
                goto label_140009ce4;
            
            if (!rbx)
            {
                rax_14 = sub_140009470(&var_68, r15, arg2, rsi);
                goto label_140009cd1;
            }
            
            rbx -= 1;
            
            if (rbx > 1)
                rbx_1 = *var_54_1[4];
            else
            {
                var_68 = NO_ERROR;
                void* r15_1 = arg2 + rsi;
                numberOfBytesWritten = 0;
                rbx_1 = *numberOfBytesWritten[4];
                int16_t* r12_3 = arg2;
                
                if (arg2 < r15_1)
                {
                    int32_t rsi_1 = 0;
                    
                    while (true)
                    {
                        int16_t r13_1 = *r12_3;
                        
                        if (_putwch_nolock(r13_1) == r13_1)
                        {
                            rsi_1 += 2;
                            numberOfBytesWritten = rsi_1;
                            
                            if (r13_1 != 0xa)
                                goto label_140009c9f;
                            
                            if (_putwch_nolock(0xd) == 0xd)
                            {
                                rsi_1 += 1;
                                numberOfBytesWritten = rsi_1;
                                rbx_1 += 1;
                                label_140009c9f:
                                r12_3 = &r12_3[1];
                                
                                if (r12_3 >= r15_1)
                                    break;
                                
                                continue;
                            }
                        }
                        
                        var_68 = GetLastError();
                        break;
                    }
                }
                
                var_58_1 = var_68;
            }
        }
        
        if (var_58_1 >> 0x20)
            return var_54_1 - rbx_1;
        
        if (var_58_1)
        {
            if (var_58_1 != 5)
                __acrt_errno_map_os_error(var_58_1);
            else
            {
                *_errno() = 9;
                *__doserrno() = 5;
            }
            
            return 0xffffffff;
        }
        
        if (!(*((&data_140017630)[r12_2] + r14_3 + 0x38) & 0x40) || *arg2 != 0x1a)
        {
            *_errno() = 0x1c;
            *__doserrno() = 0;
            return 0xffffffff;
        }
    }
    
    return 0;
}

double log10(double arg1[0x2] @ zmm0, double arg2[0x2] @ zmm6)
{
    double var_38[0x2] = arg2;
    
    if (data_140017c44)
    {
        uint64_t temp0_9[0x2] = __vpsrlq_xmmdq_xmmdq_immb(arg1, 0x34);
        double rax_4 = arg1[0];
        __vcvtdq2pd_xmmdq_xmmq(__vpsubq_xmmdq_xmmdq_memdq(temp0_9, data_140011b20)[0]);
        __vcomisd_xmmq_memq((arg1 & data_140011af0)[0], inf.0);
        
        if (rax_4 == 0x7ff0000000000000)
            return rax_4;
        
        if (rax_4 != -0x10000000000000)
            return _log10_special(arg1[0], rax_4 | 0x8000000000000, 3);
        
        uint128_t temp0_33 = __vmovsd_xmmdq_memq(-nan.0);
        int64_t rax_8;
        int512_t zmm6_1;
        rax_8 = _log10_special(arg1[0], temp0_33, 2);
        zmm6_1 = var_38;
        return rax_8;
    }
    
    uint64_t zmm4[0x2] = arg1;
    uint64_t temp0[0x2] = _mm_srli_epi64(arg1, 0x34);
    double rax = arg1[0];
    uint64_t zmm3[0x2] = __psubq_xmmdq_memdq(temp0, data_140011b20);
    uint64_t temp0_2[0x2] = __andpd_xmmxuq_memxuq(arg1, data_140011af0);
    
    if (temp0_2[0] == inf.0)
    {
        if (rax == 0x7ff0000000000000)
            return rax;
        
        if (rax != -0x10000000000000)
            return rax | 0x8000000000000;
    }
    else
    {
        arg2 = _mm_cvtepi32_pd(zmm3[0]);
        uint64_t temp0_4[0x2] = _mm_xor_pd(temp0_2, temp0_2);
        arg1[0] - temp0_4[0];
        
        if (!(arg1[0] <= temp0_4[0]))
        {
            uint128_t zmm2 = arg1 & data_140011b40;
            zmm4[0] = zmm4[0] - 1.0;
            
            if (arg2[0] == -1023.0)
            {
                zmm2 = (zmm2 | data_140011bd0) - 1.0;
                temp0_4[0] = zmm2;
                zmm2 &= data_140011b40;
                rax = zmm2;
                arg2 = _mm_cvtepi32_pd(__psubd_xmmdq_memdq(_mm_srli_epi64(temp0_4, 0x34), 
                    data_140011c70)[0]);
            }
            
            int64_t rax_2 = (rax & 0xff00000000000) + ((rax & 0x80000000000) << 1);
            uint128_t zmm1;
            uint64_t zmm5[0x2];
            
            if (!(__andpd_xmmxuq_memxuq(zmm4, data_140011cc0)[0] < 0.0625))
            {
                uint64_t rax_3 = rax_2 >> 0x2c;
                zmm1 = (rax_2 | data_140011be0) - (zmm2 | data_140011be0);
                zmm1 = zmm1 * *(&data_140012d50 + (rax_3 << 3));
                zmm2 = zmm1;
                arg1 = zmm1;
                zmm3 = 0x3fc5555555555555;
                zmm3[0] = zmm3[0] * zmm2;
                zmm1 = 0x3fd5555555555555 * zmm2;
                arg1[0] = arg1[0] * zmm2;
                zmm4 = arg1;
                zmm3[0] = zmm3[0] + 0.20000000000000001;
                zmm1 = zmm1 + 0.5;
                zmm4[0] = zmm4[0] * arg1[0];
                zmm3[0] = zmm3[0] * zmm2;
                zmm1 = zmm1 * arg1[0];
                zmm3[0] = zmm3[0] + 0.25;
                zmm1 = zmm1 + zmm2;
                zmm3[0] = zmm3[0] * zmm4[0];
                zmm1 = zmm1 + zmm3[0];
                zmm5 = 0x3e03ef3fde623e25;
                zmm1 = zmm1 * 0.43429448190325182;
                zmm5[0] = zmm5[0] * arg2[0];
                zmm5[0] = zmm5[0] - zmm1;
                arg1 = *(&data_140011d30 + (rax_3 << 3));
                zmm2 = *(&data_140012540 + (rax_3 << 3));
                zmm4 = 0x3fd3441350000000;
                zmm4[0] = zmm4[0] * arg2[0];
                arg1[0] = arg1[0] + zmm4[0];
                zmm2 = zmm2 + zmm5[0];
                arg1[0] = arg1[0] + zmm2;
                return rax_3;
            }
            
            arg1[0] = arg1[0] - 1.0;
            zmm2 = 0x4000000000000000 + arg1[0];
            zmm1 = arg1 / zmm2;
            zmm4 = 0x3f89999999bac6d4;
            zmm5 = 0x3f3c8034c85dfff0;
            arg1[0] = arg1[0] * zmm1;
            zmm1 = zmm1 + zmm1;
            zmm2 = zmm1 * zmm1;
            zmm4[0] = zmm4[0] * zmm2;
            zmm5[0] = zmm5[0] * zmm2;
            zmm4[0] = zmm4[0] + 0.083333333333331788;
            zmm5[0] = zmm5[0] + 0.0022321399879194482;
            zmm2 = zmm2 * zmm1;
            zmm4[0] = zmm4[0] * zmm2;
            zmm2 = zmm2 * zmm2;
            zmm2 = zmm2 * zmm1;
            zmm5[0] = zmm5[0] * zmm2;
            zmm2 = 0x3ea8a93728719535;
            zmm4[0] = zmm4[0] + zmm5[0];
            zmm4[0] = zmm4[0] - arg1[0];
            arg2 = 0x3fdbcb7800000000;
            zmm3 = arg1 & data_140011d10;
            arg1[0] = arg1[0] - zmm3[0];
            zmm4[0] = zmm4[0] + arg1[0];
            arg1 = zmm3;
            zmm4[0] = zmm4[0] * zmm2;
            arg1[0] = arg1[0] * zmm2;
            zmm1 = zmm4 * arg2[0];
            zmm3[0] = zmm3[0] * arg2[0];
            arg1[0] = arg1[0] + zmm4[0];
            arg1[0] = arg1[0] + zmm1;
            arg1[0] = arg1[0] + zmm3[0];
            return rax_2;
        }
        
        if (!(arg1[0] != temp0_4[0]))
            return _log10_special(arg1[0], -0x10000000000000, 1);
    }
    
    return _log10_special(arg1[0], -0x8000000000000, 2);
}

int64_t common_lseek_nolock<int64_t>(int32_t arg1, int64_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    int64_t rbx = arg1;
    HANDLE hFile = sub_140006bb0(rbx);
    int64_t newFilePointer;
    
    if (hFile != -1)
    {
        if (SetFilePointerEx(hFile, arg2, &newFilePointer, arg3))
        {
            int64_t result = newFilePointer;
            
            if (result != -1)
            {
                uint64_t rdx_3 = (rbx & 0x3f) << 6;
                int64_t rcx_5 = (&data_140017630)[rbx >> 6];
                *(rcx_5 + rdx_3 + 0x38) &= 0xfd;
                return result;
            }
        }
        else
            __acrt_errno_map_os_error(GetLastError());
    }
    else
        *_errno() = 9;
    return -1;
}

int64_t j_common_lseek_nolock<int64_t>(int32_t arg1, int64_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    /* tailcall */
    return common_lseek_nolock<int64_t>(arg1, arg2, arg3);
}

uint64_t sub_14000a470(int32_t* arg1)
{
    int64_t* rbx = arg1;
    
    if (!arg1)
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
        return 0xffffffff;
    }
    
    int32_t rdi_1 = -1;
    
    if (arg1[5] >> 0xd & 1)
    {
        rdi_1 = __acrt_stdio_flush_nolock(arg1);
        __acrt_stdio_free_buffer_nolock(rbx);
        
        if (_close(_fileno(rbx)) >= 0)
        {
            int64_t rcx_3 = rbx[5];
            
            if (rcx_3)
            {
                _free_base(rcx_3);
                rbx[5] = 0;
            }
        }
        else
            rdi_1 = -1;
    }
    
    sub_14000ab0c(rbx);
    return rdi_1;
}

uint64_t sub_14000a4f4(int64_t* arg1)
{
    int64_t* arg_8 = arg1;
    int32_t* rbx = arg1;
    int32_t rax;
    rax = arg1;
    
    if (rax)
    {
        if (!(*(arg1 + 0x14) >> 0xc & 1))
        {
            sub_140008520(arg1);
            int32_t rax_4 = sub_14000a470(rbx);
            sub_14000852c(rbx);
            return rax_4;
        }
        
        sub_14000ab0c(arg1);
    }
    else
    {
        *_errno() = 0x16;
        _invalid_parameter_noinfo();
    }
    
    return 0xffffffff;
}

uint64_t _putwch_nolock(int16_t arg1)
{
    int16_t buffer = arg1;
    HANDLE hConsoleOutput = data_1400168c0;
    
    if (hConsoleOutput == -2)
    {
        __dcrt_lowio_initialize_console_output();
        hConsoleOutput = data_1400168c0;
    }
    
    void numberOfCharsWritten;
    
    if (hConsoleOutput != -1
            && WriteConsoleW(hConsoleOutput, &buffer, 1, &numberOfCharsWritten, nullptr))
        return buffer;
    
    return 0xffff;
}

int512_t sub_14000a5bc(int32_t arg1, int64_t arg2, int64_t arg3, int32_t arg4)
{
    int32_t var_38 = arg1;
    int64_t var_20 = arg2;
    int64_t zmm3;
    int64_t var_28 = zmm3;
    int64_t r8;
    int64_t var_30 = r8;
    sub_14000af90(arg4, 0xffc0);
    int32_t rax;
    int512_t result;
    rax = __acrt_invoke_user_matherr(&var_38);
    
    if (!rax)
        _set_errno_from_matherr(arg1);
    
    result = arg3;
    return result;
}

int64_t sub_14000a624(int32_t arg1, int64_t arg2)
{
    int32_t rbx_1 = arg1 & 0x1f;
    char rdi = arg1;
    
    if (arg1 & 8 && arg2 < 0)
    {
        sub_14000b00c(1);
        rbx_1 &= 0xfffffff7;
    }
    else if (4 & rdi && TEST_BITQ(arg2, 9))
    {
        sub_14000b00c(4);
        rbx_1 &= 0xfffffffb;
    }
    else if (rdi & 1 && TEST_BITQ(arg2, 0xa))
    {
        sub_14000b00c(8);
        rbx_1 &= 0xfffffffe;
    }
    else if (rdi & 2 && TEST_BITQ(arg2, 0xb))
    {
        if (rdi & 0x10)
            sub_14000b00c(0x10);
        
        rbx_1 &= 0xfffffffd;
    }
    
    if (rdi & 0x10 && TEST_BITQ(arg2, 0xc))
    {
        sub_14000b00c(0x20);
        rbx_1 &= 0xffffffef;
    }
    
    int64_t result;
    result = !rbx_1;
    return result;
}

uint64_t sub_14000a6e0(int64_t arg1, int32_t arg2, int64_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int64_t arg7, int32_t arg8)
{
    void var_118;
    int64_t rax_1 = __security_cookie ^ &var_118;
    uint64_t var_d8 = sub_14000af90(0x1f80, 0xffc0);
    uint64_t rdx = var_d8;
    int64_t var_d0 = arg3;
    uint128_t zmm6 = arg7;
    int64_t arg_38;
    
    if (!sub_14000a624(arg5, rdx))
    {
        if (arg8 == 2)
        {
            uint64_t var_88_1 = zmm6;
            int32_t var_78;
            int32_t var_78_1 = (var_78 & 0xffffffe3) | 3;
        }
        
        void var_b8;
        _raise_exc(&var_b8, &var_d8, arg5, arg2, &arg_38, &var_d0);
        /* no return */
    }
    
    uint64_t result;
    
    if (!__acrt_has_user_matherr() || !arg4)
    {
        _set_errno_from_matherr(arg4);
        result = sub_14000af90(var_d8, 0xffc0);
        int512_t zmm0_1;
        zmm0_1 = var_d0;
    }
    else
    {
        int512_t zmm3;
        zmm3 = arg_38;
        uint64_t var_e8_1 = var_d8;
        int64_t var_f0_2 = var_d0;
        uint64_t var_f8_2 = zmm6;
        result = sub_14000a5bc(arg4, arg6, arg1, arg4);
    }
    
    __security_check_cookie(rax_1 ^ &var_118);
    return result;
}

int64_t __acrt_initialize_fma3(int64_t arg1 @ xcr0)
{
    int32_t r8 = 0;
    data_140017c40 = 0;
    int32_t temp0;
    int32_t temp1;
    int32_t temp2;
    int32_t temp3;
    temp0 = __cpuid(1, 0);
    int32_t var_18 = temp0;
    int32_t var_10 = temp2;
    int32_t var_14 = temp1;
    int32_t var_c = temp3;
    
    if ((temp2 & 0x18001000) == 0x18001000)
    {
        int32_t temp0_1;
        char temp1_1;
        temp0_1 = _xgetbv(0, arg1);
        r8 = data_140017c40;
        
        if (((temp0_1 << 0x20 | temp1_1) & 6) == 6)
            r8 = 1;
        
        data_140017c40 = r8;
    }
    
    data_140017c44 = r8;
    return 0;
}

int64_t _log10_special(int64_t arg1 @ zmm0, int128_t arg2 @ zmm1, int32_t arg3)
{
    return sub_14000a8a0(arg1, arg2, arg3, 0x1b, "log10");
}

int64_t sub_14000a8a0(int64_t arg1 @ zmm0, int128_t arg2 @ zmm1, int32_t arg3, int32_t arg4, int64_t arg5)
{
    int128_t zmm6 = arg2;
    
    if (arg3 == 1)
    {
        int32_t var_28_2 = 1;
        zmm6 = sub_14000a6e0(arg5, arg4, arg2, 2, 4, 0x22, arg1, {0});
    }
    else if (arg3 == 2)
    {
        int32_t var_28_1 = arg3 - 1;
        zmm6 = sub_14000a6e0(arg5, arg4, arg2, arg3 - 1, 8, 0x21, arg1, {0});
    }
    
    return zmm6;
}

uint64_t __crt_seh_guarded_call<class <lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0>,class <lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec>& __ptr64,class <lambda_237c231691f317818eb88cc1d5d642d6>,int32_t>::operator()<class <lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0>,class <lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec>& __ptr64,class <lambda_237c231691f317818eb88cc1d5d642d6> >(int64_t arg1, int32_t* arg2, int64_t* arg3, int32_t* arg4)
{
    int32_t* arg_20 = arg4;
    __acrt_lowio_unlock_fh(*arg2);
    int64_t rcx_1 = **arg3;
    int32_t rbx_1;
    
    if (!(*((&data_140017630)[rcx_1 >> 6] + ((rcx_1 & 0x3f) << 6) + 0x38) & 1))
    {
        *_errno() = 9;
        rbx_1 = -1;
    }
    else
        rbx_1 = sub_14000aa50(rcx_1);
    
    sub_140006ad0(*arg4);
    return rbx_1;
}

uint64_t _close(int32_t arg1)
{
    int32_t arg_8 = arg1;
    int64_t rdx = arg1;
    
    if (rdx != 0xfffffffe)
    {
        if (arg1 >= 0 && rdx < data_140017a30
            && *((&data_140017630)[rdx >> 6] + ((rdx & 0x3f) << 6) + 0x38) & 1)
        {
            int32_t arg_18 = rdx;
            int32_t arg_20 = rdx;
            int32_t* var_18 = &arg_8;
            void arg_10;
            return __crt_seh_guarded_call<class <lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0>,class <lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec>& __ptr64,class <lambda_237c231691f317818eb88cc1d5d642d6>,int32_t>::operator()<class <lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0>,class <lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec>& __ptr64,class <lambda_237c231691f317818eb88cc1d5d642d6> >(
                &arg_10, &arg_20, &var_18, &arg_18);
        }
        
        *__doserrno() = 0;
        *_errno() = 9;
        _invalid_parameter_noinfo();
    }
    else
    {
        *__doserrno() = 0;
        *_errno() = 9;
    }
    
    return 0xffffffff;
}

int64_t sub_14000aa50(int32_t arg1)
{
    int64_t rdi = arg1;
    enum WIN32_ERROR rbx_2;
    
    if (sub_140006bb0(rdi) != -1)
    {
        void* rax_1 = data_140017630;
        int64_t rax_2;
        int64_t rax_3;
        
        if ((rdi == 1 && *(rax_1 + 0xb8) & rdi) || (rdi == 2 && *(rax_1 + 0x78) & 1))
        {
            rax_2 = sub_140006bb0(2);
            rax_3 = sub_140006bb0(1);
        }
        
        if (((rdi == 1 && *(rax_1 + 0xb8) & rdi) || (rdi == 2 && *(rax_1 + 0x78) & 1))
                && rax_3 == rax_2)
            rbx_2 = NO_ERROR;
        else if (CloseHandle(sub_140006bb0(rdi)))
            rbx_2 = NO_ERROR;
        else
            rbx_2 = GetLastError();
    }
    else
        rbx_2 = NO_ERROR;
    
    sub_140006af4(rdi);
    *((&data_140017630)[rdi >> 6] + ((rdi & 0x3f) << 6) + 0x38) = 0;
    
    if (!rbx_2)
        return 0;
    
    __acrt_errno_map_os_error(rbx_2);
    return 0xffffffff;
}

int64_t* sub_14000ab0c(int64_t* arg1)
{
    *arg1 = 0;
    arg1[1] = 0;
    arg1[2] = 0;
    arg1[3] = 0xffffffff;
    *(arg1 + 0x1c) = 0;
    arg1[4] = 0;
    arg1[5] = 0;
    *(arg1 + 0x14);
    *(arg1 + 0x14) = 0;
    return arg1;
}

HANDLE __dcrt_lowio_initialize_console_output()
{
    HANDLE result = CreateFileW(u"CONOUT$", 0x40000000, FILE_SHARE_READ | FILE_SHARE_WRITE, 
        nullptr, OPEN_EXISTING, SECURITY_ANONYMOUS, nullptr);
    data_1400168c0 = result;
    return result;
}

void* __termconout()
{
    HANDLE hObject = data_1400168c0;
    void* result = hObject + 2;
    
    if (result <= 1)
        return result;
    
    return CloseHandle(hObject);
}

uint64_t _get_fpsr(int32_t arg1 @ mxcsr) __pure
{
    return arg1;
}

int64_t _set_fpsr() __pure
{
    int32_t rcx;
    int32_t arg_8 = rcx;
}

int64_t _fclrf(int32_t arg1 @ mxcsr) __pure
{
    int32_t arg_8 = arg1 & 0xffffffc0;
}

int64_t _frnd(double arg1) __pure
{
    return;
}

void _raise_exc(uint64_t arg1, int64_t* arg2, char arg3, int32_t arg4, int32_t* arg5, int32_t* arg6) __noreturn
{
    _raise_exc_ex(arg1, arg2, arg3, arg4, arg5, arg6, 0);
    /* no return */
}

int64_t sub_14000ac32() __pure
{
    return;
}

void _raise_exc_ex(uint64_t arg1, int64_t* arg2, char arg3, int32_t arg4, int32_t* arg5, int32_t* arg6, int32_t arg7) __noreturn
{
    uint64_t arguments = arg1;
    uint32_t dwExceptionCode = -0x3ffffff3;
    *(arg1 + 4) = 0;
    *(arguments + 8) = 0;
    *(arguments + 0xc) = 0;
    
    if (arg3 & 0x10)
    {
        uint64_t arguments_1 = arguments;
        dwExceptionCode = -0x3fffff71;
        *(arguments_1 + 4) |= 1;
    }
    
    if (arg3 & 2)
    {
        uint64_t arguments_2 = arguments;
        dwExceptionCode = -0x3fffff6d;
        *(arguments_2 + 4) |= 2;
    }
    
    if (arg3 & 1)
    {
        uint64_t arguments_3 = arguments;
        dwExceptionCode = -0x3fffff6f;
        *(arguments_3 + 4) |= 4;
    }
    
    if (arg3 & 4)
    {
        uint64_t arguments_4 = arguments;
        dwExceptionCode = -0x3fffff72;
        *(arguments_4 + 4) |= 8;
    }
    
    if (arg3 & 8)
    {
        uint64_t arguments_5 = arguments;
        dwExceptionCode = -0x3fffff70;
        *(arguments_5 + 4) |= 0x10;
    }
    
    uint64_t arguments_22 = arguments;
    *(arguments_22 + 8) ^= (~(*arg2 >> 7 << 4) ^ *(arguments_22 + 8)) & 0x10;
    uint64_t arguments_23 = arguments;
    *(arguments_23 + 8) ^= (~(*arg2 >> 9 << 3) ^ *(arguments_23 + 8)) & 8;
    uint64_t arguments_24 = arguments;
    *(arguments_24 + 8) ^= (~(*arg2 >> 0xa << 2) ^ *(arguments_24 + 8)) & 4;
    uint64_t arguments_25 = arguments;
    *(arguments_25 + 8) ^= (~((*arg2 >> 0xb) * 2) ^ *(arguments_25 + 8)) & 2;
    uint64_t arguments_26 = arguments;
    *(arguments_26 + 8) ^= (~(*arg2 >> 0xc) ^ *(arguments_26 + 8)) & 1;
    char rax_31 = _statfp();
    
    if (rax_31 & 1)
    {
        uint64_t arguments_27 = arguments;
        *(arguments_27 + 0xc) |= 0x10;
    }
    
    if (rax_31 & 4)
    {
        uint64_t arguments_28 = arguments;
        *(arguments_28 + 0xc) |= 8;
    }
    
    if (rax_31 & 8)
    {
        uint64_t arguments_6 = arguments;
        *(arguments_6 + 0xc) |= 4;
    }
    
    if (rax_31 & 0x10)
    {
        uint64_t arguments_7 = arguments;
        *(arguments_7 + 0xc) |= 2;
    }
    
    if (rax_31 & 0x20)
    {
        uint64_t arguments_8 = arguments;
        *(arguments_8 + 0xc) |= 1;
    }
    
    int64_t rax_33 = *arg2 & 0x6000;
    
    if (!rax_33)
    {
        uint64_t arguments_14 = arguments;
        *arguments_14 &= 0xfffffffc;
    }
    else if (rax_33 == 0x2000)
    {
        uint64_t arguments_12 = arguments;
        *arguments_12 &= 0xfffffffd;
        uint64_t arguments_13 = arguments;
        *arguments_13 |= 1;
    }
    else if (rax_33 == 0x4000)
    {
        uint64_t arguments_10 = arguments;
        *arguments_10 &= 0xfffffffe;
        uint64_t arguments_11 = arguments;
        *arguments_11 |= 2;
    }
    else if (rax_33 == 0x6000)
    {
        uint64_t arguments_9 = arguments;
        *arguments_9 |= 3;
    }
    
    uint64_t arguments_15 = arguments;
    *arguments_15 &= 0xfffe001f;
    int32_t* arguments_16 = arguments;
    *arguments_16 |= (arg4 & 0xfff) << 5;
    uint64_t arguments_17 = arguments;
    *(arguments_17 + 0x20) |= 1;
    
    if (!arg7)
    {
        uint64_t arguments_29 = arguments;
        *(arguments_29 + 0x20) = (*(arguments_29 + 0x20) & 0xffffffe3) | 2;
        *(arguments + 0x10) = *arg5;
        uint64_t arguments_21 = arguments;
        *(arguments_21 + 0x60) |= 1;
        uint64_t arguments_30 = arguments;
        *(arguments_30 + 0x60) = (*(arguments_30 + 0x60) & 0xffffffe3) | 2;
        *(arguments + 0x50) = *arg6;
    }
    else
    {
        uint64_t arguments_18 = arguments;
        *(arguments_18 + 0x20) &= 0xffffffe1;
        *(arguments + 0x10) = *arg5;
        uint64_t arguments_19 = arguments;
        *(arguments_19 + 0x60) |= 1;
        uint64_t arguments_20 = arguments;
        *(arguments_20 + 0x60) &= 0xffffffe1;
        *(arguments + 0x50) = *arg6;
    }
    
    _clrfp();
    RaiseException(dwExceptionCode, 0, 1, &arguments);
    /* no return */
}

uint64_t _set_errno_from_matherr(int32_t arg1)
{
    uint64_t result;
    
    if (arg1 == 1)
    {
        result = _errno();
        *result = 0x21;
    }
    else
    {
        result = arg1 - 2;
        
        if (result <= 1)
        {
            result = _errno();
            *result = 0x22;
        }
    }
    
    return result;
}

uint64_t _clrfp()
{
    int32_t mxcsr;
    return _get_fpsr(mxcsr) & 0x3f;
}

uint64_t sub_14000af90(int32_t arg1, int32_t arg2)
{
    int32_t mxcsr;
    int32_t rax = _get_fpsr(mxcsr);
    int32_t arg_10 = rax;
    int32_t arg_8 = ((~arg2 | 0xffff807f) & rax) | (arg1 & arg2);
    data_1400168d0;
    return rax;
}

int64_t sub_14000b00c(int32_t arg1)
{
    /* tailcall */
    return _set_fpsr();
}

uint64_t _statfp()
{
    int32_t mxcsr;
    return _get_fpsr(mxcsr) & 0x3f;
}

BOOL IsProcessorFeaturePresent(enum PROCESSOR_FEATURE_ID ProcessorFeature)
{
    /* tailcall */
    return IsProcessorFeaturePresent(ProcessorFeature);
}

void RtlUnwindEx(void* TargetFrame, void* TargetIp, EXCEPTION_RECORD* ExceptionRecord, void* ReturnValue, CONTEXT* ContextRecord, UNWIND_HISTORY_TABLE* HistoryTable)
{
    /* tailcall */
    return RtlUnwindEx(TargetFrame, TargetIp, ExceptionRecord, ReturnValue, ContextRecord, 
        HistoryTable);
}

void* _FindPESection(void* arg1, int64_t arg2)
{
    int32_t r9 = 0;
    void* r8 = *(arg1 + 0x3c) + arg1;
    uint32_t r11 = *(r8 + 6);
    void* result = *(r8 + 0x14) + 0x18 + r8;
    
    if (r11)
    {
        do
        {
            uint64_t rdx = *(result + 0xc);
            
            if (arg2 >= rdx && arg2 < *(result + 8) + rdx)
                return result;
            
            r9 += 1;
            result += 0x28;
        } while (r9 < r11);
    }
    
    return nullptr;
}

void* _IsNonwritableInCurrentImage(int64_t arg1)
{
    void* result = _ValidateImageBase(&__dos_header);
    
    if (result)
    {
        result = _FindPESection(&__dos_header, arg1 - &__dos_header);
        
        if (result)
            return ~(*(result + 0x24) >> 0x1f) & 1;
    }
    
    return result;
}

int64_t _ValidateImageBase(int16_t* arg1)
{
    if (*arg1 != 0x5a4d)
        return 0;
    
    void* rcx_1 = *(arg1 + 0x3c) + arg1;
    int64_t result = 0;
    
    if (*rcx_1 == 0x4550)
        result = *(rcx_1 + 0x18) == 0x20b;
    
    return result;
}

uint64_t memcmp(char* arg1, int64_t arg2, int64_t arg3)
{
    char* rdx = arg2 - arg1;
    uint64_t rax;
    bool c_1;
    
    if (arg3 >= 8)
    {
        while (arg1 & 7)
        {
            rax = *arg1;
            char temp4_1 = *(rdx + arg1);
            c_1 = rax < temp4_1;
            
            if (rax != temp4_1)
                goto label_14000b173;
            
            arg1 = &arg1[1];
            arg3 -= 1;
        }
        
        uint64_t r9_2 = arg3 >> 3;
        
        if (r9_2)
        {
            uint64_t i_2 = r9_2 >> 2;
            
            if (i_2)
            {
                uint64_t i;
                
                do
                {
                    rax = *arg1;
                    
                    if (rax != *(rdx + arg1))
                        goto label_14000b1e4;
                    
                    rax = *(arg1 + 8);
                    
                    if (rax != *(rdx + arg1 + 8))
                        goto label_14000b1e0;
                    
                    rax = *(arg1 + 0x10);
                    
                    if (rax != *(rdx + arg1 + 0x10))
                        goto label_14000b1dc;
                    
                    rax = *(arg1 + 0x18);
                    
                    if (rax != *(rdx + arg1 + 0x18))
                    {
                        arg1 = &arg1[8];
                        label_14000b1dc:
                        arg1 = &arg1[8];
                        label_14000b1e0:
                        arg1 = &arg1[8];
                        label_14000b1e4:
                        uint64_t rcx = *(arg1 + rdx);
                        uint64_t rax_4 = _bswap(rax);
                        int32_t rax_5 = rax_4 - rax_4;
                        bool c_4 = /* bool c_4 = unimplemented  {sbb eax, eax} */;
                        return rax_5 + 1;
                    }
                    
                    arg1 = &arg1[0x20];
                    i = i_2;
                    i_2 -= 1;
                } while (i != 1);
                arg3 &= 0x1f;
            }
            
            uint64_t i_3 = arg3 >> 3;
            
            if (i_3)
            {
                uint64_t i_1;
                
                do
                {
                    rax = *arg1;
                    
                    if (rax != *(rdx + arg1))
                        goto label_14000b1e4;
                    
                    arg1 = &arg1[8];
                    i_1 = i_3;
                    i_3 -= 1;
                } while (i_1 != 1);
                arg3 &= 7;
            }
        }
    }
    
    if (!arg3)
        return 0;
    
    while (true)
    {
        rax = *arg1;
        char temp0_1 = *(rdx + arg1);
        c_1 = rax < temp0_1;
        
        if (rax != temp0_1)
            break;
        
        arg1 = &arg1[1];
        int64_t temp3_1 = arg3;
        arg3 -= 1;
        
        if (temp3_1 == 1)
            return 0;
    }
    
    label_14000b173:
    bool c_2 = /* bool c_2 = unimplemented  {sbb eax, eax} */;
    return rax - rax + 1;
}

void _guard_dispatch_icall_nop(void (* arg1)())
{
    int64_t rax;
    /* jump -> rax */
}

uint64_t _callthreadstart$filt$0(int64_t* arg1)
{
    return _XcptFilter(**arg1, arg1);
}

uint64_t __scrt_is_nonwritable_in_current_image$filt$0(int64_t* arg1)
{
    int32_t rcx;
    rcx = **arg1 == 0xc0000005;
    return rcx;
}

int64_t common_exit::filt$0::filt$0(int64_t* arg1)
{
    return dyntls_init_exception_filter(**arg1);
}

int64_t __crt_seh_guarded_call<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a>,void>::operator()<class <lambda_410d79af7f07d98d83a3f525b3859a53>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36>& __ptr64,class <lambda_38119f0e861e05405d8a144b9b982f0a> >::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return __vcrt_lock(**(arg2 + 0x58));
}

int64_t sub_14000b28b()
{
    /* tailcall */
    return __vcrt_lock(0);
}

int64_t __crt_seh_guarded_call<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff>,void>::operator()<class <lambda_46352004c1216016012b18bd6f87e700>,class <lambda_3bd07e1a1191394380780325891bf33f>& __ptr64,class <lambda_334532d3f185bcaa59b5be82d7d22bff> >::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return __vcrt_lock(**(arg2 + 0x48));
}

int64_t update_thread_multibyte_data_internal::fin$0::fin$0()
{
    /* tailcall */
    return __vcrt_lock(5);
}

int64_t sub_14000b2d4()
{
    /* tailcall */
    return __vcrt_lock(7);
}

int64_t __acrt_uninitialize_locale$fin$0()
{
    /* tailcall */
    return __vcrt_lock(4);
}

void raise$fin$0(int64_t arg1, void* arg2)
{
    if (*(arg2 + 0x80))
        __vcrt_lock(3);
}

int64_t __crt_seh_guarded_call<class <lambda_33460c761a2fd0112426625c267a43ce>,class <lambda_64051b05716dd7c405450ad92739bf96>& __ptr64,class <lambda_86f04418403019f79950d0188666236b>,int32_t>::operator()<class <lambda_33460c761a2fd0112426625c267a43ce>,class <lambda_64051b05716dd7c405450ad92739bf96>& __ptr64,class <lambda_86f04418403019f79950d0188666236b> >::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return sub_14000852c(**(arg2 + 0x48));
}

int64_t __crt_seh_guarded_call<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752>,void>::operator()<class <lambda_886d6c58226a84441f68b9f2b8217b83>,class <lambda_ab61a845afdef5b7c387490eaf3616ee>& __ptr64,class <lambda_f7f22ab5edc0698d5f6905b0d3f44752> >::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return __vcrt_lock(**(arg2 + 0x98));
}

int64_t common_flush_all$fin$1()
{
    /* tailcall */
    return __vcrt_lock(8);
}

int64_t common_lseek<long>::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return sub_140006ad0(*(arg2 + 0x50));
}

int64_t fflush$fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return sub_14000852c(*(arg2 + 0x30));
}

int64_t __crt_seh_guarded_call<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707>,void>::operator()<class <lambda_fb3a7dec4e47f37f22dae91bb15c9095>,class <lambda_698284760c8add0bfb0756c19673e34b>& __ptr64,class <lambda_dfb8eca1e75fef3034a8fb18dd509707> >::fin$0::fin$0(int64_t arg1, void* arg2)
{
    /* tailcall */
    return sub_140006ad0(**(arg2 + 0x48));
}

int64_t _ctrlfp$filt$0(int64_t* arg1)
{
    int32_t* rax = *arg1;
    
    if (*rax != 0xc0000005 && *rax != 0xc000001d)
        return 0;
    
    return 1;
}

uint64_t _heapwalk$filt$0(int64_t* arg1)
{
    int32_t rcx;
    rcx = **arg1 == 0xc0000005;
    return rcx;
}

