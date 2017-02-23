#ifndef AZIFEMNAMESPACE_CUTS_CXX
#define AZIFEMNAMESPACE_CUTS_CXX

namespace azifem {
    const Float_t UUzdcBinEdges[3] = {-1, 436.5, 523.5}; // UU193 - 0%, 0.25%, 0.5%
    const Float_t AuAuzdcBinEdges[3] = {-1, 1194.5, 1389.5}; // AuAu 200 - 0, 0.25, 0.5
    const Float_t q2BinEdges[6] = {0,0.4925,0.7525,1.0075,1.3275,10}; 
    const Float_t UUmult[6] = {200, 570, 589, 605, 623, 10000}; // UU 193
    const Float_t AuAumult[6] = {200, 501, 522, 538, 556, 10000}; // AuAu 200

    Int_t getZdcBin(const Float_t zdc, const Bool_t uuNotAuAu);
}

Int_t azifem::getZdcBin(const Float_t zdc, const Bool_t uuNotAuAu)
{

    Int_t zdcBin = -1;
    Float_t zdcLow = 999999;
    Float_t zdcHigh = -1;

    for(Int_t i = 0; i <= 2; i++)
    {
        if(uuNotAuAu) {
            zdcLow = UUzdcBinEdges[i];
            zdcHigh = UUzdcBinEdges[i+1];
        } else {
            zdcLow = AuAuzdcBinEdges[i];
            zdcHigh = AuAuzdcBinEdges[i+1];
        }

        if( (zdc > zdcLow) && (zdc <= zdcHigh) ) { zdcBin = i; }

    }

    return zdcBin;
}

Int_t azifem::getq2Bin(const Double_t q2)
{

    Int_t q2Bin = -1;

    for(Int_t i = 0; i <= 5; i++)
    {
        if( (q2 > q2BinEdges[i]) && (q2 <= q2BinEdges[i+1]) ) {q2Bin = i;}

    }

    return q2Bin;

}

#endif
