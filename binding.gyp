{
    "targets": [
        {
            "target_name": "morfeusz2",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["./src/main.cpp"],
            "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")", "./headers"],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "conditions": [
                ['OS=="mac"', {"libraries": ["../libmorfeusz2.dylib"]}],
                ['OS=="linux"', {"libraries": ["../libmorfeusz2.so"]}]
            ],
        }
    ]
}