#ifndef BATTLESHIPS_Exports_H
#define BATTLESHIPS_Exports_H

#ifdef _MSC_VER
    // disable warnings
    #pragma warning(disable:4996)
    // disable private members in dll export warnings
    #pragma warning(disable:4251)
    #if defined(BUILD_SHARED_LIB)
        #define EXPORTS __declspec(dllexport)
        #define SEXPORTS 1
    #else
		#define EXPORTS __declspec(dllimport)
        #define SEXPORTS 2
    #endif
    
    #define SKIP_DLL
    #define EXPORT_DLL
#else
    #define EXPORTS // Unix like systems including Mac
    #define SEXPORTS 0

    #if __GNUC__ >= 4
        #define SKIP_DLL __attribute__((visibility("hidden")))
        #define EXPORT_DLL __attribute__((visibility("default")))
    #else
        #define SKIP_DLL
        #define EXPORT_DLL
    #endif
#endif


// define any constant if present

#define X_SIZE 10
#define Y_SIZE 10
constexpr const int kTotalSumofNonZeros = 63;

#endif
// ************************************************************************* //