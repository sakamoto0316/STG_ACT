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
 48;
 -12.47339;15.66006;-13.30109;,
 0.89046;18.45329;-13.72833;,
 0.00000;0.00000;-17.92159;,
 -13.68245;1.84634;-14.07076;,
 12.24715;12.96555;-13.83130;,
 16.75584;0.05957;-14.98404;,
 0.41794;-12.89329;-17.73989;,
 -10.28236;-8.63768;-12.68156;,
 12.09541;-10.83468;-13.10705;,
 12.24715;12.96555;-13.83130;,
 13.74190;20.25990;-1.01552;,
 16.14561;0.00210;-0.79406;,
 16.75584;0.05957;-14.98404;,
 13.89354;17.58123;11.78489;,
 15.49088;-0.44085;12.09462;,
 14.87029;-10.77934;-2.95332;,
 12.09541;-10.83468;-13.10705;,
 11.72747;-9.73457;11.35009;,
 13.89354;17.58123;11.78489;,
 2.09293;20.13494;12.72946;,
 0.00000;0.00000;17.92159;,
 15.49088;-0.44085;12.09462;,
 -12.76590;18.17879;10.00313;,
 -13.77042;1.25560;15.32271;,
 -1.18668;-10.73993;16.07337;,
 11.72747;-9.73457;11.35009;,
 -13.29021;-6.73741;15.97330;,
 -12.76590;18.17879;10.00313;,
 -14.46171;19.61596;2.93668;,
 -17.92159;0.00000;0.00000;,
 -13.77042;1.25560;15.32271;,
 -12.47339;15.66006;-13.30109;,
 -13.68245;1.84634;-14.07076;,
 -18.05403;-9.20191;0.49460;,
 -13.29021;-6.73741;15.97330;,
 -10.28236;-8.63768;-12.68156;,
 0.00000;22.10990;0.00000;,
 -14.46171;19.61596;2.93668;,
 13.74190;20.25990;-1.01552;,
 0.89046;18.45329;-13.72833;,
 -12.47339;15.66006;-13.30109;,
 12.24715;12.96555;-13.83130;,
 -18.05403;-9.20191;0.49460;,
 -1.06581;-13.26227;-0.08664;,
 14.87029;-10.77934;-2.95332;,
 -10.28236;-8.63768;-12.68156;,
 0.41794;-12.89329;-17.73989;,
 12.09541;-10.83468;-13.10705;;
 
 24;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;3,2,6,7;,
 4;2,5,8,6;,
 4;9,10,11,12;,
 4;10,13,14,11;,
 4;12,11,15,16;,
 4;11,14,17,15;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;21,20,24,25;,
 4;20,23,26,24;,
 4;27,28,29,30;,
 4;28,31,32,29;,
 4;30,29,33,34;,
 4;29,32,35,33;,
 4;27,19,36,37;,
 4;19,13,38,36;,
 4;37,36,39,40;,
 4;36,38,41,39;,
 4;42,43,24,34;,
 4;43,44,17,24;,
 4;45,46,43,42;,
 4;46,47,44,43;;
 
 MeshMaterialList {
  1;
  24;
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
  }
 }
 MeshNormals {
  50;
  -0.170448;0.151511;-0.973649;,
  0.079993;0.464576;-0.881913;,
  -0.524623;-0.054155;-0.849611;,
  -0.034388;0.023327;-0.999136;,
  -0.675654;-0.160570;-0.719520;,
  -0.049789;-0.128652;-0.990439;,
  0.215713;0.607222;-0.764689;,
  0.986351;0.163662;-0.018071;,
  0.205480;0.030973;-0.978171;,
  0.998367;-0.057110;-0.001574;,
  0.272065;-0.120513;-0.954703;,
  0.961088;-0.275833;0.015060;,
  0.994068;0.103548;0.033264;,
  0.032970;0.219244;0.975113;,
  0.992882;-0.085269;0.083150;,
  0.075164;0.046240;0.996099;,
  0.953826;-0.270834;0.129866;,
  0.115191;-0.129389;0.984881;,
  -0.178796;0.284679;0.941801;,
  -0.989399;0.144315;0.016189;,
  -0.152344;0.120527;0.980951;,
  -0.999226;0.026789;-0.028817;,
  -0.121447;-0.047142;0.991478;,
  -0.992536;-0.096021;-0.075185;,
  0.021117;0.997169;-0.072168;,
  -0.068760;-0.996584;0.045750;,
  0.972411;0.222743;-0.069293;,
  0.995776;-0.028112;-0.087408;,
  0.955607;-0.277174;-0.099946;,
  0.243080;0.142796;0.959438;,
  0.298812;-0.030871;0.953812;,
  0.344595;-0.203509;0.916427;,
  -0.958416;0.132834;0.252575;,
  -0.961937;0.064805;0.265474;,
  -0.964017;0.147575;-0.221119;,
  -0.960835;-0.003535;0.277098;,
  -0.140674;0.969351;0.201416;,
  0.021097;0.982544;0.184828;,
  -0.180315;0.983146;-0.030185;,
  0.182306;0.969583;0.163320;,
  0.223925;0.968207;-0.111505;,
  -0.209966;0.942473;-0.260115;,
  -0.293464;-0.955392;0.033241;,
  -0.058218;-0.985330;0.160422;,
  -0.266215;-0.946586;0.181944;,
  0.157568;-0.985931;0.055788;,
  0.152412;-0.979510;0.131644;,
  -0.313983;-0.942288;-0.116226;,
  -0.078453;-0.994427;-0.070432;,
  0.161807;-0.986612;-0.020392;;
  24;
  4;0,1,3,2;,
  4;1,6,8,3;,
  4;2,3,5,4;,
  4;3,8,10,5;,
  4;26,7,9,27;,
  4;7,12,14,9;,
  4;27,9,11,28;,
  4;9,14,16,11;,
  4;29,13,15,30;,
  4;13,18,20,15;,
  4;30,15,17,31;,
  4;15,20,22,17;,
  4;32,19,21,33;,
  4;19,34,34,21;,
  4;33,21,23,35;,
  4;21,2,4,23;,
  4;36,37,24,38;,
  4;37,39,40,24;,
  4;38,24,41,41;,
  4;24,40,6,1;,
  4;42,25,43,44;,
  4;25,45,46,43;,
  4;47,48,25,42;,
  4;48,49,45,25;;
 }
 MeshTextureCoords {
  48;
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;;
 }
}