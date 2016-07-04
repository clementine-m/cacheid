# cacheid
Explore the parameters of the cache with cpuid

## Usage

Example on my Intel Core i5-5200U:

    $ make

    $ ./cacheid 

    -- Level: 1 (data cache)
    Not inclusive of lower cache levels
    Cache addressing: direct mapped cache
    Line size: 64
    Number of ways: 8
    Number of sets: 64
    Raw results:
    0x00000004 0x00: eax=0x1c004121 ebx=0x01c0003f ecx=0x0000003f edx=0x00000000

    -- Level: 1 (instruction cache)
    Not inclusive of lower cache levels
    Cache addressing: direct mapped cache
    Line size: 64
    Number of ways: 8
    Number of sets: 64
    Raw results:
    0x00000004 0x01: eax=0x1c004122 ebx=0x01c0003f ecx=0x0000003f edx=0x00000000

    -- Level: 2 (unified cache)
    Not inclusive of lower cache levels
    Cache addressing: direct mapped cache
    Line size: 64
    Number of ways: 8
    Number of sets: 512
    Raw results:
    0x00000004 0x02: eax=0x1c004143 ebx=0x01c0003f ecx=0x000001ff edx=0x00000000

    -- Level: 3 (unified cache)
    Inclusive of lower cache levels
    Cache addressing: complex addressing
    Line size: 64
    Number of ways: 12
    Number of sets: 4096
    Raw results:
    0x00000004 0x03: eax=0x1c03c163 ebx=0x02c0003f ecx=0x00000fff edx=0x00000006


