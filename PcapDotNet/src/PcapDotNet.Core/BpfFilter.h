#pragma once

#include "PcapTypedefs.h"
#include "PcapAddress.h"

struct bpf_program;

namespace PcapDotNet 
{
    public ref class BpfFilter : System::IDisposable
    {
    public:
        BpfFilter(pcap_t* handler, System::String^ filterString, IpV4SocketAddress^ netmask);

        ~BpfFilter(); // IDisposable

        property bpf_program& Bpf
        {
            bpf_program& get();
        }

    private:
        bpf_program* _bpf;
    };
}