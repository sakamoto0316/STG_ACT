xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 158;
 -2.37848;-2.94992;1.01028;,
 -1.27675;-2.94992;1.68245;,
 -2.67917;-4.29378;3.16443;,
 -4.80754;-4.29378;1.86590;,
 -0.00000;-2.94992;1.92848;,
 -0.00000;-4.29378;3.63973;,
 1.27675;-2.94992;1.68245;,
 2.67917;-4.29378;3.16443;,
 2.37848;-2.94992;1.01028;,
 4.80754;-4.29378;1.86590;,
 2.78174;-2.94992;0.09208;,
 5.58658;-4.29378;0.09208;,
 2.78174;-2.94992;0.09208;,
 2.37848;-2.94992;-0.82612;,
 4.80754;-4.29378;-1.68175;,
 5.58658;-4.29378;0.09208;,
 1.27675;-2.94992;-1.49829;,
 2.67917;-4.29378;-2.98028;,
 0.00000;-2.94992;-1.74433;,
 0.00000;-4.29378;-3.45558;,
 -1.27675;-2.94992;-1.49829;,
 -2.67917;-4.29378;-2.98028;,
 -2.37848;-2.94992;-0.82612;,
 -4.80754;-4.29378;-1.68175;,
 -2.78174;-2.94992;0.09208;,
 -5.58658;-4.29378;0.09208;,
 -2.78174;-2.94992;0.09208;,
 -5.58658;-4.29378;0.09208;,
 -5.08399;-7.07107;6.48128;,
 -8.64004;-7.07107;4.48089;,
 -0.00000;-7.07107;7.33860;,
 5.08399;-7.07107;6.48128;,
 8.64004;-7.07107;4.48089;,
 10.42317;-6.14838;0.09208;,
 8.86171;-7.07107;-3.53119;,
 10.42317;-6.14838;0.09208;,
 5.08359;-7.07107;-6.62699;,
 0.00000;-7.07107;-7.07327;,
 -5.08359;-7.07107;-6.62699;,
 -8.86171;-7.07107;-3.53119;,
 -10.42317;-6.14838;0.09208;,
 -10.42317;-6.14838;0.09208;,
 -4.69740;-5.00000;6.15931;,
 -7.97849;-5.00000;4.63677;,
 -0.00000;-5.00000;6.87595;,
 4.69740;-5.00000;6.15931;,
 7.97849;-5.00000;4.63677;,
 9.77839;-5.00000;0.09208;,
 7.97849;-5.00000;-3.98853;,
 9.77839;-5.00000;0.09208;,
 4.32685;-5.00000;-6.30087;,
 0.00000;-5.00000;-6.85597;,
 -4.32685;-5.00000;-6.30087;,
 -7.97849;-5.00000;-3.98853;,
 -9.77839;-5.00000;0.09208;,
 -9.77839;-5.00000;0.09208;,
 -4.33783;-2.58819;5.43877;,
 -7.74456;-2.58819;4.28271;,
 -0.00000;-2.58819;6.24623;,
 4.33783;-2.58819;5.43877;,
 7.74456;-2.58819;4.28271;,
 8.84136;-2.58819;0.09208;,
 7.62556;-2.58819;-3.96761;,
 8.84136;-2.58819;0.09208;,
 3.57901;-2.58819;-5.96732;,
 0.00000;-2.58819;-6.52886;,
 -3.57901;-2.58819;-5.96732;,
 -7.62556;-2.58819;-3.96761;,
 -8.84136;-2.58819;0.09208;,
 -8.84136;-2.58819;0.09208;,
 -3.45690;0.00000;5.22919;,
 -7.19661;0.00000;3.63973;,
 0.00000;0.00000;5.92929;,
 3.45690;0.00000;5.22919;,
 7.19661;0.00000;3.63973;,
 8.11017;0.00000;0.09208;,
 7.19661;0.00000;-3.45558;,
 8.11017;0.00000;0.09208;,
 3.13094;0.00000;-5.65412;,
 0.00000;0.00000;-6.05004;,
 -3.13094;0.00000;-5.65412;,
 -7.19661;0.00000;-3.45558;,
 -8.11017;0.00000;0.09208;,
 -8.11017;0.00000;0.09208;,
 -3.18852;2.58819;5.06290;,
 -6.43476;2.58819;3.51885;,
 0.00000;2.58819;5.57827;,
 3.18852;2.58819;5.06290;,
 6.43476;2.58819;3.51885;,
 7.08568;2.58819;0.09208;,
 6.43476;2.58819;-3.33470;,
 7.08568;2.58819;0.09208;,
 2.36633;2.58819;-5.12513;,
 0.00000;2.58819;-5.53754;,
 -2.36633;2.58819;-5.12513;,
 -6.43476;2.58819;-3.33470;,
 -7.08568;2.58819;0.09208;,
 -7.08568;2.58819;0.09208;,
 -2.68884;5.00000;4.56659;,
 -5.69675;5.00000;3.16443;,
 0.00000;5.00000;4.97045;,
 2.68884;5.00000;4.56659;,
 5.69675;5.00000;3.16443;,
 6.49560;5.00000;0.09208;,
 5.69675;5.00000;-2.98028;,
 6.49560;5.00000;0.09208;,
 1.90834;5.00000;-4.49304;,
 0.00000;5.00000;-4.97772;,
 -1.90834;5.00000;-4.49304;,
 -5.69675;5.00000;-2.98028;,
 -6.49560;5.00000;0.09208;,
 -6.49560;5.00000;0.09208;,
 -2.03698;7.07107;3.74428;,
 -4.65589;7.07107;2.60065;,
 0.00000;7.07107;4.10777;,
 2.03698;7.07107;3.74428;,
 4.65589;7.07107;2.60065;,
 5.75761;7.07107;0.09208;,
 4.65589;7.07107;-2.41650;,
 5.75761;7.07107;0.09208;,
 1.68394;7.07107;-3.93286;,
 0.00000;7.07107;-4.18447;,
 -1.68394;7.07107;-3.93286;,
 -4.65589;7.07107;-2.41650;,
 -5.75761;7.07107;0.09208;,
 -5.75761;7.07107;0.09208;,
 -1.25993;8.66025;2.68206;,
 -4.16496;8.66025;1.86590;,
 0.00000;8.66025;2.95104;,
 1.25993;8.66025;2.68206;,
 4.16496;8.66025;1.86590;,
 4.94400;8.66025;0.09208;,
 4.16496;8.66025;-1.68175;,
 4.94400;8.66025;0.09208;,
 1.21167;8.66025;-2.83156;,
 0.00000;8.66025;-2.84889;,
 -1.21167;8.66025;-2.83156;,
 -4.16496;8.66025;-1.68175;,
 -4.94400;8.66025;0.09208;,
 -4.94400;8.66025;0.09208;,
 -0.64415;9.65926;1.68245;,
 -3.02867;10.59655;1.01028;,
 0.00000;9.65926;1.92848;,
 0.64415;9.65926;1.68245;,
 3.02867;10.59655;1.01028;,
 3.69249;9.91615;0.09208;,
 3.02867;10.59655;-0.82612;,
 3.69249;9.91615;0.09208;,
 0.64415;9.65926;-1.49829;,
 0.00000;9.65926;-1.74433;,
 -0.64415;9.65926;-1.49829;,
 -3.02867;10.59655;-0.82612;,
 -3.69249;9.91615;0.09208;,
 -3.69249;9.91615;0.09208;,
 -0.00000;-2.45614;0.09208;,
 -0.00000;-2.45614;0.09208;,
 0.00000;8.84649;0.09208;,
 0.00000;8.84649;0.09208;;
 
 144;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;12,13,14,15;,
 4;13,16,17,14;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;26,0,3,27;,
 4;3,2,28,29;,
 4;2,5,30,28;,
 4;5,7,31,30;,
 4;7,9,32,31;,
 4;9,11,33,32;,
 4;15,14,34,35;,
 4;14,17,36,34;,
 4;17,19,37,36;,
 4;19,21,38,37;,
 4;21,23,39,38;,
 4;23,25,40,39;,
 4;27,3,29,41;,
 4;29,28,42,43;,
 4;28,30,44,42;,
 4;30,31,45,44;,
 4;31,32,46,45;,
 4;32,33,47,46;,
 4;35,34,48,49;,
 4;34,36,50,48;,
 4;36,37,51,50;,
 4;37,38,52,51;,
 4;38,39,53,52;,
 4;39,40,54,53;,
 4;41,29,43,55;,
 4;43,42,56,57;,
 4;42,44,58,56;,
 4;44,45,59,58;,
 4;45,46,60,59;,
 4;46,47,61,60;,
 4;49,48,62,63;,
 4;48,50,64,62;,
 4;50,51,65,64;,
 4;51,52,66,65;,
 4;52,53,67,66;,
 4;53,54,68,67;,
 4;55,43,57,69;,
 4;57,56,70,71;,
 4;56,58,72,70;,
 4;58,59,73,72;,
 4;59,60,74,73;,
 4;60,61,75,74;,
 4;63,62,76,77;,
 4;62,64,78,76;,
 4;64,65,79,78;,
 4;65,66,80,79;,
 4;66,67,81,80;,
 4;67,68,82,81;,
 4;69,57,71,83;,
 4;71,70,84,85;,
 4;70,72,86,84;,
 4;72,73,87,86;,
 4;73,74,88,87;,
 4;74,75,89,88;,
 4;77,76,90,91;,
 4;76,78,92,90;,
 4;78,79,93,92;,
 4;79,80,94,93;,
 4;80,81,95,94;,
 4;81,82,96,95;,
 4;83,71,85,97;,
 4;85,84,98,99;,
 4;84,86,100,98;,
 4;86,87,101,100;,
 4;87,88,102,101;,
 4;88,89,103,102;,
 4;91,90,104,105;,
 4;90,92,106,104;,
 4;92,93,107,106;,
 4;93,94,108,107;,
 4;94,95,109,108;,
 4;95,96,110,109;,
 4;97,85,99,111;,
 4;99,98,112,113;,
 4;98,100,114,112;,
 4;100,101,115,114;,
 4;101,102,116,115;,
 4;102,103,117,116;,
 4;105,104,118,119;,
 4;104,106,120,118;,
 4;106,107,121,120;,
 4;107,108,122,121;,
 4;108,109,123,122;,
 4;109,110,124,123;,
 4;111,99,113,125;,
 4;113,112,126,127;,
 4;112,114,128,126;,
 4;114,115,129,128;,
 4;115,116,130,129;,
 4;116,117,131,130;,
 4;119,118,132,133;,
 4;118,120,134,132;,
 4;120,121,135,134;,
 4;121,122,136,135;,
 4;122,123,137,136;,
 4;123,124,138,137;,
 4;125,113,127,139;,
 4;127,126,140,141;,
 4;126,128,142,140;,
 4;128,129,143,142;,
 4;129,130,144,143;,
 4;130,131,145,144;,
 4;133,132,146,147;,
 4;132,134,148,146;,
 4;134,135,149,148;,
 4;135,136,150,149;,
 4;136,137,151,150;,
 4;137,138,152,151;,
 4;139,127,141,153;,
 3;1,0,154;,
 3;4,1,154;,
 3;6,4,154;,
 3;8,6,154;,
 3;10,8,154;,
 3;13,12,155;,
 3;16,13,155;,
 3;18,16,155;,
 3;20,18,155;,
 3;22,20,155;,
 3;24,22,155;,
 3;0,26,154;,
 3;141,140,156;,
 3;140,142,156;,
 3;142,143,156;,
 3;143,144,156;,
 3;144,145,156;,
 3;147,146,157;,
 3;146,148,157;,
 3;148,149,157;,
 3;149,150,157;,
 3;150,151,157;,
 3;151,152,157;,
 3;153,141,156;;
 
 MeshMaterialList {
  1;
  144;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\murabito00_UV.png";
   }
  }
 }
 MeshNormals {
  160;
  0.258414;-0.935665;-0.240320;,
  0.147527;-0.906352;-0.395932;,
  0.000000;-0.895033;-0.446000;,
  -0.147527;-0.906352;-0.395932;,
  -0.258414;-0.935665;-0.240320;,
  -0.305283;-0.952262;-0.000000;,
  -0.258414;-0.935665;0.240320;,
  -0.147528;-0.906352;0.395931;,
  0.000000;-0.895033;0.445999;,
  0.147528;-0.906352;0.395931;,
  0.258414;-0.935665;0.240320;,
  0.305283;-0.952262;-0.000000;,
  0.355686;-0.863703;-0.357079;,
  0.198686;-0.814569;-0.544979;,
  0.000000;-0.794423;-0.607364;,
  -0.198686;-0.814569;-0.544979;,
  -0.355686;-0.863703;-0.357079;,
  -0.429664;-0.902969;0.005966;,
  -0.365152;-0.860945;0.354170;,
  -0.202766;-0.818322;0.537806;,
  0.000000;-0.795405;0.606078;,
  0.202766;-0.818322;0.537806;,
  0.365152;-0.860945;0.354170;,
  0.429664;-0.902969;0.005966;,
  0.348701;-0.857729;-0.377767;,
  0.193995;-0.817546;-0.542204;,
  0.000000;-0.800586;-0.599218;,
  -0.193995;-0.817546;-0.542204;,
  -0.348701;-0.857729;-0.377767;,
  -0.427166;-0.904093;0.012069;,
  -0.367612;-0.852362;0.371942;,
  -0.202129;-0.824990;0.527764;,
  0.000000;-0.802504;0.596646;,
  0.202129;-0.824990;0.527764;,
  0.367612;-0.852362;0.371942;,
  0.427166;-0.904093;0.012069;,
  -0.695877;0.269621;0.665628;,
  -0.284906;0.219967;0.932976;,
  0.000000;0.240415;0.970670;,
  0.284906;0.219967;0.932976;,
  0.695877;0.269621;0.665628;,
  0.945504;0.325180;-0.016733;,
  0.733211;0.256989;-0.629570;,
  0.334124;0.173129;-0.926492;,
  0.000000;0.150209;-0.988654;,
  -0.334124;0.173129;-0.926492;,
  -0.733211;0.256989;-0.629570;,
  -0.945504;0.325180;-0.016733;,
  -0.707961;0.276777;0.649758;,
  -0.265849;0.225542;0.937259;,
  0.000000;0.206654;0.978414;,
  0.265849;0.225542;0.937259;,
  0.707961;0.276777;0.649758;,
  0.966120;0.257771;-0.012913;,
  0.746658;0.231464;-0.623639;,
  0.307258;0.177900;-0.934850;,
  0.000000;0.159623;-0.987178;,
  -0.307258;0.177900;-0.934850;,
  -0.746658;0.231464;-0.623639;,
  -0.966120;0.257771;-0.012913;,
  -0.728766;0.267851;0.630203;,
  -0.282013;0.154650;0.946864;,
  0.000000;0.121004;0.992652;,
  0.282013;0.154650;0.946864;,
  0.728766;0.267851;0.630203;,
  0.955852;0.293811;-0.004647;,
  0.748129;0.276158;-0.603356;,
  0.293812;0.209094;-0.932713;,
  0.000000;0.189567;-0.981868;,
  -0.293812;0.209094;-0.932713;,
  -0.748129;0.276158;-0.603356;,
  -0.955852;0.293811;-0.004647;,
  -0.744407;0.272779;0.609467;,
  -0.289648;0.185207;0.939043;,
  0.000000;0.174698;0.984622;,
  0.289648;0.185207;0.939043;,
  0.744407;0.272779;0.609467;,
  0.952810;0.303569;0.000000;,
  0.737169;0.305695;-0.602605;,
  0.289235;0.245110;-0.925346;,
  0.000000;0.234780;-0.972049;,
  -0.289235;0.245110;-0.925346;,
  -0.737169;0.305695;-0.602605;,
  -0.952810;0.303569;0.000000;,
  -0.705238;0.374893;0.601742;,
  -0.273856;0.332844;0.902340;,
  0.000000;0.318030;0.948081;,
  0.273856;0.332844;0.902340;,
  0.705238;0.374893;0.601742;,
  0.934659;0.355546;0.000000;,
  0.702041;0.356536;-0.616458;,
  0.289358;0.295849;-0.910355;,
  0.000000;0.285951;-0.958244;,
  -0.289358;0.295849;-0.910355;,
  -0.702041;0.356536;-0.616458;,
  -0.934659;0.355546;0.000000;,
  -0.628077;0.486123;0.607621;,
  -0.242231;0.493680;0.835227;,
  0.000000;0.498825;0.866703;,
  0.242231;0.493680;0.835227;,
  0.628077;0.486123;0.607621;,
  0.895978;0.444099;0.000001;,
  0.646873;0.459910;-0.608307;,
  0.251396;0.462471;-0.850248;,
  0.000000;0.475953;-0.879471;,
  -0.251396;0.462471;-0.850248;,
  -0.646873;0.459910;-0.608307;,
  -0.895978;0.444099;0.000001;,
  -0.532607;0.600797;0.596131;,
  -0.180196;0.623175;0.761040;,
  0.000000;0.674631;0.738155;,
  0.180196;0.623175;0.761040;,
  0.532607;0.600797;0.596131;,
  0.834352;0.551232;0.000001;,
  0.547357;0.612763;-0.570019;,
  0.154971;0.664084;-0.731421;,
  0.000000;0.711362;-0.702826;,
  -0.154971;0.664084;-0.731421;,
  -0.547357;0.612763;-0.570019;,
  -0.834352;0.551232;0.000001;,
  -0.462804;0.678190;0.570851;,
  -0.139141;0.673084;0.726359;,
  0.000000;0.746913;0.664922;,
  0.139141;0.673084;0.726359;,
  0.462804;0.678190;0.570851;,
  0.771283;0.636493;0.000001;,
  0.462949;0.707740;-0.533651;,
  0.101251;0.733064;-0.672581;,
  0.000000;0.793208;-0.608950;,
  -0.101251;0.733064;-0.672581;,
  -0.462949;0.707740;-0.533651;,
  -0.771283;0.636493;0.000001;,
  0.000000;-1.000000;-0.000000;,
  0.022250;0.997083;-0.073003;,
  -0.689985;0.269191;0.671906;,
  -0.306923;0.177907;0.934958;,
  0.000000;0.200937;0.979604;,
  0.306923;0.177907;0.934958;,
  0.689985;0.269191;0.671906;,
  0.919308;0.393179;-0.016823;,
  0.723949;0.294526;-0.623821;,
  0.351719;0.181903;-0.918262;,
  0.000000;0.145501;-0.989358;,
  -0.351719;0.181903;-0.918262;,
  -0.723949;0.294526;-0.623821;,
  -0.919308;0.393179;-0.016823;,
  0.320964;0.811588;-0.488166;,
  0.288402;0.894907;-0.340537;,
  0.000000;0.914440;-0.404721;,
  -0.288402;0.894907;-0.340537;,
  -0.320964;0.811588;-0.488166;,
  -0.205494;0.709369;-0.674216;,
  -0.205494;0.709369;0.674216;,
  -0.320964;0.811589;0.488166;,
  -0.288405;0.894907;0.340536;,
  0.000000;0.914441;0.404719;,
  0.288405;0.894907;0.340536;,
  0.320964;0.811589;0.488166;,
  0.205494;0.709369;0.674216;,
  0.205494;0.709369;-0.674216;;
  144;
  4;0,1,13,12;,
  4;1,2,14,13;,
  4;2,3,15,14;,
  4;3,4,16,15;,
  4;4,5,17,16;,
  4;5,6,18,17;,
  4;6,7,19,18;,
  4;7,8,20,19;,
  4;8,9,21,20;,
  4;9,10,22,21;,
  4;10,11,23,22;,
  4;11,0,12,23;,
  4;12,13,25,24;,
  4;13,14,26,25;,
  4;14,15,27,26;,
  4;15,16,28,27;,
  4;16,17,29,28;,
  4;17,18,30,29;,
  4;18,19,31,30;,
  4;19,20,32,31;,
  4;20,21,33,32;,
  4;21,22,34,33;,
  4;22,23,35,34;,
  4;23,12,24,35;,
  4;134,135,37,36;,
  4;135,136,38,37;,
  4;136,137,39,38;,
  4;137,138,40,39;,
  4;138,139,41,40;,
  4;139,140,42,41;,
  4;140,141,43,42;,
  4;141,142,44,43;,
  4;142,143,45,44;,
  4;143,144,46,45;,
  4;144,145,47,46;,
  4;145,134,36,47;,
  4;36,37,49,48;,
  4;37,38,50,49;,
  4;38,39,51,50;,
  4;39,40,52,51;,
  4;40,41,53,52;,
  4;41,42,54,53;,
  4;42,43,55,54;,
  4;43,44,56,55;,
  4;44,45,57,56;,
  4;45,46,58,57;,
  4;46,47,59,58;,
  4;47,36,48,59;,
  4;48,49,61,60;,
  4;49,50,62,61;,
  4;50,51,63,62;,
  4;51,52,64,63;,
  4;52,53,65,64;,
  4;53,54,66,65;,
  4;54,55,67,66;,
  4;55,56,68,67;,
  4;56,57,69,68;,
  4;57,58,70,69;,
  4;58,59,71,70;,
  4;59,48,60,71;,
  4;60,61,73,72;,
  4;61,62,74,73;,
  4;62,63,75,74;,
  4;63,64,76,75;,
  4;64,65,77,76;,
  4;65,66,78,77;,
  4;66,67,79,78;,
  4;67,68,80,79;,
  4;68,69,81,80;,
  4;69,70,82,81;,
  4;70,71,83,82;,
  4;71,60,72,83;,
  4;72,73,85,84;,
  4;73,74,86,85;,
  4;74,75,87,86;,
  4;75,76,88,87;,
  4;76,77,89,88;,
  4;77,78,90,89;,
  4;78,79,91,90;,
  4;79,80,92,91;,
  4;80,81,93,92;,
  4;81,82,94,93;,
  4;82,83,95,94;,
  4;83,72,84,95;,
  4;84,85,97,96;,
  4;85,86,98,97;,
  4;86,87,99,98;,
  4;87,88,100,99;,
  4;88,89,101,100;,
  4;89,90,102,101;,
  4;90,91,103,102;,
  4;91,92,104,103;,
  4;92,93,105,104;,
  4;93,94,106,105;,
  4;94,95,107,106;,
  4;95,84,96,107;,
  4;96,97,109,108;,
  4;97,98,110,109;,
  4;98,99,111,110;,
  4;99,100,112,111;,
  4;100,101,113,112;,
  4;101,102,114,113;,
  4;102,103,115,114;,
  4;103,104,116,115;,
  4;104,105,117,116;,
  4;105,106,118,117;,
  4;106,107,119,118;,
  4;107,96,108,119;,
  4;108,109,121,120;,
  4;109,110,122,121;,
  4;110,111,123,122;,
  4;111,112,124,123;,
  4;112,113,125,124;,
  4;113,114,126,125;,
  4;114,115,127,126;,
  4;115,116,128,127;,
  4;116,117,129,128;,
  4;117,118,130,129;,
  4;118,119,131,130;,
  4;119,108,120,131;,
  3;1,0,132;,
  3;2,1,132;,
  3;3,2,132;,
  3;4,3,132;,
  3;5,4,132;,
  3;6,5,132;,
  3;7,6,132;,
  3;8,7,132;,
  3;9,8,132;,
  3;10,9,132;,
  3;11,10,132;,
  3;0,11,132;,
  3;146,147,133;,
  3;147,148,133;,
  3;148,149,133;,
  3;149,150,133;,
  3;150,151,133;,
  3;152,153,152;,
  3;153,154,133;,
  3;154,155,133;,
  3;155,156,133;,
  3;156,157,133;,
  3;157,158,133;,
  3;159,146,133;;
 }
 MeshTextureCoords {
  158;
  0.574887;0.558981;,
  0.564907;0.558981;,
  0.577611;0.573345;,
  0.596892;0.573345;,
  0.553341;0.558981;,
  0.553341;0.573345;,
  0.541775;0.558981;,
  0.529070;0.573345;,
  0.531794;0.558981;,
  0.509789;0.573345;,
  0.528141;0.558981;,
  0.502732;0.573345;,
  0.178738;0.880944;,
  0.187932;0.880944;,
  0.132552;0.917095;,
  0.114790;0.917095;,
  0.213051;0.880944;,
  0.181077;0.917095;,
  0.242160;0.880944;,
  0.242160;0.917095;,
  0.271269;0.880944;,
  0.303242;0.917095;,
  0.296387;0.880944;,
  0.351767;0.917095;,
  0.305581;0.880944;,
  0.369529;0.917095;,
  0.578540;0.558981;,
  0.603949;0.573345;,
  0.599396;0.603031;,
  0.631611;0.603031;,
  0.553341;0.603031;,
  0.507285;0.603031;,
  0.475071;0.603031;,
  0.458917;0.593168;,
  0.040120;0.991808;,
  0.004520;0.966986;,
  0.126258;0.991808;,
  0.242160;0.991808;,
  0.358061;0.991808;,
  0.444199;0.991808;,
  0.479799;0.966986;,
  0.647764;0.593168;,
  0.595894;0.580893;,
  0.625618;0.580893;,
  0.553341;0.580893;,
  0.510787;0.580893;,
  0.481064;0.580893;,
  0.464758;0.580893;,
  0.060257;0.936093;,
  0.019220;0.936093;,
  0.143511;0.936093;,
  0.242160;0.936093;,
  0.340808;0.936093;,
  0.424063;0.936093;,
  0.465099;0.936093;,
  0.641923;0.580893;,
  0.592637;0.555114;,
  0.623498;0.555114;,
  0.553341;0.555114;,
  0.514044;0.555114;,
  0.483183;0.555114;,
  0.473247;0.555114;,
  0.068303;0.871213;,
  0.040584;0.871213;,
  0.160561;0.871213;,
  0.242160;0.871213;,
  0.323758;0.871213;,
  0.416016;0.871213;,
  0.443735;0.871213;,
  0.633434;0.555114;,
  0.584657;0.527449;,
  0.618535;0.527449;,
  0.553341;0.527449;,
  0.522025;0.527449;,
  0.488147;0.527449;,
  0.479871;0.527449;,
  0.078083;0.801588;,
  0.057254;0.801588;,
  0.170777;0.801588;,
  0.242160;0.801588;,
  0.313542;0.801588;,
  0.406236;0.801588;,
  0.427065;0.801588;,
  0.626811;0.527449;,
  0.582225;0.499784;,
  0.611633;0.499784;,
  0.553341;0.499784;,
  0.524456;0.499784;,
  0.495048;0.499784;,
  0.489152;0.499784;,
  0.095452;0.731963;,
  0.080612;0.731963;,
  0.188209;0.731963;,
  0.242160;0.731963;,
  0.296110;0.731963;,
  0.388867;0.731963;,
  0.403707;0.731963;,
  0.617530;0.499784;,
  0.577699;0.474005;,
  0.604947;0.474005;,
  0.553341;0.474005;,
  0.528982;0.474005;,
  0.501734;0.474005;,
  0.494497;0.474005;,
  0.112278;0.667082;,
  0.094065;0.667082;,
  0.198651;0.667082;,
  0.242160;0.667082;,
  0.285668;0.667082;,
  0.372041;0.667082;,
  0.390254;0.667082;,
  0.612184;0.474005;,
  0.571794;0.451868;,
  0.595518;0.451868;,
  0.553341;0.451868;,
  0.534888;0.451868;,
  0.511163;0.451868;,
  0.501182;0.451868;,
  0.136009;0.611368;,
  0.110891;0.611368;,
  0.203767;0.611368;,
  0.242160;0.611368;,
  0.280552;0.611368;,
  0.348310;0.611368;,
  0.373428;0.611368;,
  0.605499;0.451868;,
  0.564754;0.434881;,
  0.591071;0.434881;,
  0.553341;0.434881;,
  0.541927;0.434881;,
  0.515610;0.434881;,
  0.508553;0.434881;,
  0.147202;0.568617;,
  0.129441;0.568617;,
  0.214534;0.568617;,
  0.242160;0.568617;,
  0.269785;0.568617;,
  0.337117;0.568617;,
  0.354879;0.568617;,
  0.598128;0.434881;,
  0.559176;0.424203;,
  0.580777;0.414184;,
  0.553341;0.424203;,
  0.547505;0.424203;,
  0.525904;0.414184;,
  0.519890;0.421457;,
  0.173108;0.516528;,
  0.157974;0.534832;,
  0.227473;0.541742;,
  0.242160;0.541742;,
  0.256846;0.541742;,
  0.311211;0.516528;,
  0.326345;0.534832;,
  0.586791;0.421457;,
  0.553341;0.553703;,
  0.242160;0.867661;,
  0.553341;0.432890;,
  0.242160;0.563607;;
 }
}