/*
Copyright (c) 2009-2012, Structural Bioinformatics Laboratory, Boston University
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
- Neither the name of the author nor the names of its contributors may be used
  to endorse or promote products derived from this software without specific
  prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef _MOL_IO_H_
#define _MOL_IO_H_

/** \file io.h
	This file contains structures and functions
	that are used for reading from and
	writing to files
*/

typedef enum
{
	FILE_PDB,
	FILE_XYZ,
	FILE_MS, // marksur pdb
	FILE_DX, // dx grid
	FILE_POT, // potential grid
	FILE_UNKNOWN
} File_Type;

/**
  determines the file ext of path
*/
File_Type file_ext (const char* path);

/**
  prints to stderr a list of known file types
*/
void fprintf_stderr_atomgrp_file_exts ();

/**
  reads an atomgrp file based on its ext
*/
struct atomgrp* read_file_atomgrp (const char* path, struct prm* prm, float msur_k);

struct grid* read_file_grid (const char* path);

/**
  prints an atomgrp file based on its ext
*/
void fprint_file_atomgrp (const char* path, struct atomgrp* ag, struct prm* prm);

/**
  reads modified vdw parameters from pdb file 
*/
void read_mod_vdw(char *mfile, int *nmod, int **mod, double **modeps, double **modrminh);

#endif