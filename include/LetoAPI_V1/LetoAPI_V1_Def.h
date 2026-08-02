#pragma once

#define LETO_HANDLE(name) typedef struct name##__ { int leto_handle; } name

/// Opaque pointer to Font instance
LETO_HANDLE(LetoFont_V1);

/// Opaque pointer to Screen instance
LETO_HANDLE(LetoScreen_V1);

/// Opaque pointer to Bitmap instance
LETO_HANDLE(LetoBitmap_V1);

// C++ system realisation

#ifdef __cplusplus

template <typename T_Derived, typename T_Handle>
class LetoHandleImpl {
public:
    static T_Derived* FromHandle(T_Handle* h) {
        return reinterpret_cast<T_Derived*>(h);
    }
    
    static const T_Derived* FromHandle(const T_Handle* h) {
        return reinterpret_cast<const T_Derived*>(h);
    }

    static T_Handle* ToHandle(T_Derived* d) {
        return reinterpret_cast<T_Handle*>(d);
    }

    static const T_Handle* ToHandle(const T_Derived* d) {
        return reinterpret_cast<const T_Handle*>(d);
    }
};

#endif
