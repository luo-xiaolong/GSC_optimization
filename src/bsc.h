#pragma once
// *******************************************************************************************
// This file is a part of VCFShark software distributed under GNU GPL 3 licence.
// The homepage of the VCFShark project is https://github.com/refresh-bio/VCFShark
//
// Authors: Sebastian Deorowicz, Agnieszka Danek, Marek Kokot
// Version: 1.1
// Date   : 2021-02-18
// *******************************************************************************************

#include <vector>
#include "defs.h"

#include "libbsc.h"

using namespace std;

// ************************************************************************************
struct bsc_params_t {
	int block_size;
	int lzp_hash_size;
	int lzp_min_len;
	int blockSorter;
	int coder;
	
};

// ************************************************************************************
class CBSCWrapper
{
	int block_size;
	int lzp_hash_size;
	int lzp_min_len;
	int blockSorter;
	int coder;

	static int features;

public:
	CBSCWrapper();
	~CBSCWrapper();

	static bool InitLibrary(int _features);

	bool InitDecompress();
	bool InitCompress(int _block_size, int _lzp_hash_size, int _lzp_min_len, int _blockSorter, int _coder);
	bool InitCompress(bsc_params_t params);

	bool Compress(const vector<uint8_t>& v_input, vector<uint8_t>& v_output);
	static bool Decompress(vector<uint8_t>& v_input, vector<uint8_t>& v_output);
};

// EOF
