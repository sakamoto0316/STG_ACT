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
 138;
 -0.02226;-8.13848;0.91871;,
 -0.67189;-8.13848;0.64963;,
 -0.86216;-7.55210;0.83990;,
 -0.02226;-7.55210;1.18780;,
 0.62737;-8.13848;0.64963;,
 0.81764;-7.55210;0.83990;,
 0.89645;-8.13848;-0.00000;,
 1.16553;-7.55210;-0.00000;,
 0.62737;-8.13848;-0.64963;,
 0.81764;-7.55210;-0.83990;,
 -0.02226;-8.13848;-0.91871;,
 -0.02226;-7.55210;-1.18780;,
 -0.67189;-8.13848;-0.64963;,
 -0.86216;-7.55210;-0.83990;,
 -0.94097;-8.13848;0.00000;,
 -1.21006;-7.55210;0.00000;,
 -1.32152;-7.30921;1.29925;,
 -0.02226;-7.30921;1.83742;,
 1.27699;-7.30921;1.29925;,
 1.81516;-7.30921;-0.00000;,
 1.27699;-7.30921;-1.29925;,
 -0.02226;-7.30921;-1.83742;,
 -1.32152;-7.30921;-1.29926;,
 -1.85969;-7.30921;0.00000;,
 -1.78087;-7.55210;1.75861;,
 -0.02226;-7.55210;2.48705;,
 1.73635;-7.55210;1.75861;,
 2.46479;-7.55210;-0.00000;,
 1.73635;-7.55210;-1.75861;,
 -0.02226;-7.55210;-2.48705;,
 -1.78087;-7.55210;-1.75861;,
 -2.50931;-7.55210;0.00000;,
 -1.97114;-8.13848;1.94888;,
 -0.02226;-8.13848;2.75614;,
 1.92662;-8.13848;1.94888;,
 2.73387;-8.13848;-0.00000;,
 1.92662;-8.13848;-1.94888;,
 -0.02226;-8.13848;-2.75614;,
 -1.97114;-8.13848;-1.94888;,
 -2.77840;-8.13848;0.00000;,
 -1.78087;-8.72486;1.75861;,
 -0.02226;-8.72486;2.48705;,
 1.73635;-8.72486;1.75861;,
 2.46479;-8.72486;-0.00000;,
 1.73635;-8.72486;-1.75861;,
 -0.02226;-8.72486;-2.48705;,
 -1.78087;-8.72486;-1.75861;,
 -2.50931;-8.72486;0.00000;,
 -1.32152;-8.96775;1.29925;,
 -0.02226;-8.96775;1.83742;,
 1.27699;-8.96775;1.29925;,
 1.81516;-8.96775;-0.00000;,
 1.27699;-8.96775;-1.29925;,
 -0.02226;-8.96775;-1.83742;,
 -1.32152;-8.96775;-1.29926;,
 -1.85969;-8.96775;0.00000;,
 -0.86216;-8.72486;0.83990;,
 -0.02226;-8.72486;1.18780;,
 0.81764;-8.72486;0.83990;,
 1.16553;-8.72486;-0.00000;,
 0.81764;-8.72486;-0.83990;,
 -0.02226;-8.72486;-1.18780;,
 -0.86216;-8.72486;-0.83990;,
 -1.21006;-8.72486;0.00000;,
 -1.48142;-8.31369;1.19579;,
 0.00000;-8.31369;1.94497;,
 0.00000;-7.35404;4.11340;,
 -2.73731;-7.35404;2.72911;,
 1.48142;-8.31369;1.19579;,
 2.73731;-7.35404;2.72911;,
 2.09505;-8.31369;-0.00000;,
 3.87114;-7.35404;-0.00000;,
 2.09505;-8.31369;-0.00000;,
 1.48142;-8.31369;-1.80867;,
 2.73731;-7.35404;-3.34198;,
 3.87114;-7.35404;-0.00000;,
 0.00000;-8.31369;-2.55784;,
 0.00000;-7.35404;-4.66380;,
 -1.48142;-8.31369;-1.80867;,
 -2.73731;-7.35404;-3.34198;,
 -2.09505;-8.31369;0.00000;,
 -3.87114;-7.35404;0.00000;,
 -2.09505;-8.31369;0.00000;,
 -3.87114;-7.35404;0.00000;,
 0.00000;-5.91781;5.56230;,
 -3.57647;-5.91781;3.75364;,
 3.57647;-5.91781;3.75364;,
 5.05789;-5.91781;-0.00000;,
 3.57647;-5.91781;-4.36651;,
 5.05789;-5.91781;-0.00000;,
 0.00000;-5.91781;-5.18773;,
 -3.57647;-5.91781;-4.36651;,
 -5.05789;-5.91781;0.00000;,
 -5.05789;-5.91781;0.00000;,
 0.00000;-4.22367;6.07109;,
 -3.87114;-4.22367;4.11340;,
 3.87114;-4.22367;4.11340;,
 5.47462;-4.22367;-0.00000;,
 3.87114;-4.22367;-4.72628;,
 5.47462;-4.22367;-0.00000;,
 0.00000;-4.22367;-5.56547;,
 -3.87114;-4.22367;-4.72628;,
 -5.47462;-4.22367;0.00000;,
 -5.47462;-4.22367;0.00000;,
 0.00000;-2.52953;5.56230;,
 -3.57647;-2.52953;3.75364;,
 3.57647;-2.52953;3.75364;,
 5.05789;-2.52953;-0.00000;,
 3.57647;-2.52953;-4.36651;,
 5.05789;-2.52953;-0.00000;,
 0.00000;-2.52953;-5.18773;,
 -3.57647;-2.52953;-4.36651;,
 -5.05789;-2.52953;0.00000;,
 -5.05789;-2.52953;0.00000;,
 0.00000;-1.09330;4.11340;,
 -2.73731;-1.09330;2.72911;,
 2.73731;-1.09330;2.72911;,
 3.87114;-1.09330;-0.00000;,
 2.73731;-1.09330;-3.34198;,
 3.87114;-1.09330;-0.00000;,
 0.00000;-1.09330;-4.45308;,
 -2.73731;-1.09330;-3.34198;,
 -3.87114;-1.09330;0.00000;,
 -3.87114;-1.09330;0.00000;,
 0.00000;-0.13364;1.94497;,
 -1.48142;-0.13364;1.19579;,
 1.48142;-0.13364;1.19579;,
 2.09505;-0.13364;-0.00000;,
 1.48142;-0.13364;-1.80867;,
 2.09505;-0.13364;-0.00000;,
 0.00000;-0.13364;-2.55784;,
 -1.48142;-0.13364;-1.80867;,
 -2.09505;-0.13364;0.00000;,
 -2.09505;-0.13364;0.00000;,
 0.00000;-8.65068;-0.00000;,
 0.00000;-8.65068;-0.00000;,
 0.00000;0.20335;0.00000;,
 0.00000;0.20335;0.00000;;
 
 128;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;8,6,7,9;,
 4;10,8,9,11;,
 4;12,10,11,13;,
 4;14,12,13,15;,
 4;1,14,15,2;,
 4;3,2,16,17;,
 4;5,3,17,18;,
 4;7,5,18,19;,
 4;9,7,19,20;,
 4;11,9,20,21;,
 4;13,11,21,22;,
 4;15,13,22,23;,
 4;2,15,23,16;,
 4;17,16,24,25;,
 4;18,17,25,26;,
 4;19,18,26,27;,
 4;20,19,27,28;,
 4;21,20,28,29;,
 4;22,21,29,30;,
 4;23,22,30,31;,
 4;16,23,31,24;,
 4;25,24,32,33;,
 4;26,25,33,34;,
 4;27,26,34,35;,
 4;28,27,35,36;,
 4;29,28,36,37;,
 4;30,29,37,38;,
 4;31,30,38,39;,
 4;24,31,39,32;,
 4;33,32,40,41;,
 4;34,33,41,42;,
 4;35,34,42,43;,
 4;36,35,43,44;,
 4;37,36,44,45;,
 4;38,37,45,46;,
 4;39,38,46,47;,
 4;32,39,47,40;,
 4;41,40,48,49;,
 4;42,41,49,50;,
 4;43,42,50,51;,
 4;44,43,51,52;,
 4;45,44,52,53;,
 4;46,45,53,54;,
 4;47,46,54,55;,
 4;40,47,55,48;,
 4;49,48,56,57;,
 4;50,49,57,58;,
 4;51,50,58,59;,
 4;52,51,59,60;,
 4;53,52,60,61;,
 4;54,53,61,62;,
 4;55,54,62,63;,
 4;48,55,63,56;,
 4;57,56,1,0;,
 4;58,57,0,4;,
 4;59,58,4,6;,
 4;60,59,6,8;,
 4;61,60,8,10;,
 4;62,61,10,12;,
 4;63,62,12,14;,
 4;56,63,14,1;,
 4;64,65,66,67;,
 4;65,68,69,66;,
 4;68,70,71,69;,
 4;72,73,74,75;,
 4;73,76,77,74;,
 4;76,78,79,77;,
 4;78,80,81,79;,
 4;82,64,67,83;,
 4;67,66,84,85;,
 4;66,69,86,84;,
 4;69,71,87,86;,
 4;75,74,88,89;,
 4;74,77,90,88;,
 4;77,79,91,90;,
 4;79,81,92,91;,
 4;83,67,85,93;,
 4;85,84,94,95;,
 4;84,86,96,94;,
 4;86,87,97,96;,
 4;89,88,98,99;,
 4;88,90,100,98;,
 4;90,91,101,100;,
 4;91,92,102,101;,
 4;93,85,95,103;,
 4;95,94,104,105;,
 4;94,96,106,104;,
 4;96,97,107,106;,
 4;99,98,108,109;,
 4;98,100,110,108;,
 4;100,101,111,110;,
 4;101,102,112,111;,
 4;103,95,105,113;,
 4;105,104,114,115;,
 4;104,106,116,114;,
 4;106,107,117,116;,
 4;109,108,118,119;,
 4;108,110,120,118;,
 4;110,111,121,120;,
 4;111,112,122,121;,
 4;113,105,115,123;,
 4;115,114,124,125;,
 4;114,116,126,124;,
 4;116,117,127,126;,
 4;119,118,128,129;,
 4;118,120,130,128;,
 4;120,121,131,130;,
 4;121,122,132,131;,
 4;123,115,125,133;,
 3;65,64,134;,
 3;68,65,134;,
 3;70,68,134;,
 3;73,72,135;,
 3;76,73,135;,
 3;78,76,135;,
 3;80,78,135;,
 3;64,82,134;,
 3;125,124,136;,
 3;124,126,136;,
 3;126,127,136;,
 3;129,128,137;,
 3;128,130,137;,
 3;130,131,137;,
 3;131,132,137;,
 3;133,125,136;;
 
 MeshMaterialList {
  1;
  128;
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
    "TEXTURE\\murabito00_UV.png";
   }
  }
 }
 MeshNormals {
  119;
  0.707107;0.000000;-0.707107;,
  0.000000;0.000000;-1.000000;,
  -0.707109;-0.000000;-0.707105;,
  -1.000000;0.000000;0.000000;,
  -0.707109;-0.000000;0.707105;,
  0.000000;0.000000;1.000000;,
  0.707107;0.000000;0.707107;,
  1.000000;0.000000;0.000000;,
  0.475571;0.740042;-0.475572;,
  -0.000000;0.740041;-0.672562;,
  -0.475574;0.740041;-0.475572;,
  -0.672564;0.740039;0.000000;,
  -0.475574;0.740041;0.475572;,
  -0.000001;0.740042;0.672561;,
  0.475571;0.740043;0.475572;,
  0.672560;0.740043;-0.000000;,
  -0.000001;1.000000;-0.000001;,
  -0.000000;1.000000;-0.000002;,
  -0.000002;1.000000;-0.000001;,
  -0.000002;1.000000;0.000000;,
  -0.000002;1.000000;0.000001;,
  -0.000001;1.000000;0.000001;,
  -0.000002;1.000000;-0.000001;,
  -0.000003;1.000000;-0.000000;,
  -0.475573;0.740042;0.475572;,
  0.000000;0.740043;0.672559;,
  0.475573;0.740042;0.475572;,
  0.672562;0.740041;0.000000;,
  0.475573;0.740042;-0.475572;,
  0.000000;0.740043;-0.672560;,
  -0.475573;0.740041;-0.475573;,
  -0.672562;0.740041;0.000000;,
  -0.707107;-0.000000;0.707107;,
  0.707108;0.000000;0.707106;,
  1.000000;0.000000;0.000000;,
  0.707108;0.000000;-0.707106;,
  -0.707107;-0.000000;-0.707107;,
  -0.475572;-0.740043;0.475571;,
  0.000000;-0.740044;0.672559;,
  0.475572;-0.740043;0.475571;,
  0.672561;-0.740042;-0.000000;,
  0.475572;-0.740043;-0.475571;,
  0.000000;-0.740043;-0.672559;,
  -0.475572;-0.740042;-0.475572;,
  -0.672561;-0.740042;0.000000;,
  -0.000000;-1.000000;-0.000001;,
  -0.000000;-1.000000;-0.000002;,
  -0.000002;-1.000000;-0.000002;,
  -0.000002;-1.000000;0.000000;,
  -0.000002;-1.000000;0.000002;,
  -0.000001;-1.000000;0.000001;,
  -0.000002;-1.000000;-0.000001;,
  -0.000003;-1.000000;-0.000000;,
  0.475571;-0.740043;-0.475572;,
  -0.000000;-0.740042;-0.672561;,
  -0.475574;-0.740042;-0.475571;,
  -0.672564;-0.740039;0.000000;,
  -0.475574;-0.740042;0.475571;,
  -0.000001;-0.740042;0.672560;,
  0.475570;-0.740044;0.475571;,
  0.672559;-0.740044;-0.000000;,
  -0.225271;-0.949940;0.216486;,
  0.000000;-0.957362;0.288890;,
  0.225271;-0.949940;0.216486;,
  0.313808;-0.949309;0.018349;,
  0.227934;-0.954899;-0.190299;,
  0.000000;-0.962360;-0.271777;,
  -0.227934;-0.954899;-0.190299;,
  -0.313808;-0.949309;0.018349;,
  -0.445347;-0.797599;0.406819;,
  0.000000;-0.828026;0.560690;,
  0.445347;-0.797599;0.406819;,
  0.625307;-0.780047;0.022753;,
  0.460920;-0.770660;-0.440041;,
  0.000000;-0.748185;-0.663490;,
  -0.460920;-0.770660;-0.440041;,
  -0.625307;-0.780047;0.022753;,
  -0.650984;-0.479424;0.588534;,
  0.000000;-0.519769;0.854307;,
  0.650984;-0.479424;0.588534;,
  0.890279;-0.454837;0.022935;,
  0.613299;-0.436997;-0.657949;,
  0.000000;-0.371858;-0.928290;,
  -0.613299;-0.436997;-0.657949;,
  -0.890279;-0.454837;0.022935;,
  -0.740714;0.000000;0.671820;,
  0.000000;0.000000;1.000000;,
  0.740714;0.000000;0.671820;,
  0.999728;0.000000;0.023314;,
  0.668009;0.000000;-0.744153;,
  0.000000;0.000000;-1.000000;,
  -0.668009;0.000000;-0.744153;,
  -0.999728;0.000000;0.023314;,
  -0.650984;0.479424;0.588534;,
  0.000000;0.519768;0.854307;,
  0.650984;0.479424;0.588534;,
  0.890279;0.454837;0.022935;,
  0.604224;0.453612;-0.655095;,
  0.000000;0.398945;-0.916975;,
  -0.604224;0.453612;-0.655095;,
  -0.890279;0.454837;0.022935;,
  -0.445348;0.797598;0.406820;,
  0.000000;0.828024;0.560692;,
  0.445348;0.797598;0.406820;,
  0.625309;0.780045;0.022753;,
  0.446253;0.780163;-0.438411;,
  0.000000;0.758859;-0.651255;,
  -0.446253;0.780163;-0.438411;,
  -0.625309;0.780045;0.022753;,
  -0.225272;0.949940;0.216488;,
  0.000000;0.957362;0.288892;,
  0.225272;0.949940;0.216488;,
  0.313810;0.949308;0.018349;,
  0.226193;0.954282;-0.195403;,
  0.000000;0.959498;-0.281717;,
  -0.226193;0.954282;-0.195403;,
  -0.313810;0.949308;0.018349;,
  0.000000;-0.999855;0.017043;,
  0.000000;0.999855;0.017043;;
  128;
  4;1,0,8,9;,
  4;2,1,9,10;,
  4;3,2,10,11;,
  4;4,3,11,12;,
  4;5,4,12,13;,
  4;6,5,13,14;,
  4;7,6,14,15;,
  4;0,7,15,8;,
  4;9,8,16,17;,
  4;10,9,17,18;,
  4;11,10,18,19;,
  4;12,11,19,20;,
  4;13,12,20,21;,
  4;14,13,21,22;,
  4;15,14,22,23;,
  4;8,15,23,16;,
  4;17,16,24,25;,
  4;18,17,25,26;,
  4;19,18,26,27;,
  4;20,19,27,28;,
  4;21,20,28,29;,
  4;22,21,29,30;,
  4;23,22,30,31;,
  4;16,23,31,24;,
  4;25,24,32,5;,
  4;26,25,5,33;,
  4;27,26,33,34;,
  4;28,27,34,35;,
  4;29,28,35,1;,
  4;30,29,1,36;,
  4;31,30,36,3;,
  4;24,31,3,32;,
  4;5,32,37,38;,
  4;33,5,38,39;,
  4;34,33,39,40;,
  4;35,34,40,41;,
  4;1,35,41,42;,
  4;36,1,42,43;,
  4;3,36,43,44;,
  4;32,3,44,37;,
  4;38,37,45,46;,
  4;39,38,46,47;,
  4;40,39,47,48;,
  4;41,40,48,49;,
  4;42,41,49,50;,
  4;43,42,50,51;,
  4;44,43,51,52;,
  4;37,44,52,45;,
  4;46,45,53,54;,
  4;47,46,54,55;,
  4;48,47,55,56;,
  4;49,48,56,57;,
  4;50,49,57,58;,
  4;51,50,58,59;,
  4;52,51,59,60;,
  4;45,52,60,53;,
  4;54,53,0,1;,
  4;55,54,1,2;,
  4;56,55,2,3;,
  4;57,56,3,4;,
  4;58,57,4,5;,
  4;59,58,5,6;,
  4;60,59,6,7;,
  4;53,60,7,0;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;63,64,72,71;,
  4;64,65,73,72;,
  4;65,66,74,73;,
  4;66,67,75,74;,
  4;67,68,76,75;,
  4;68,61,69,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;76,69,77,84;,
  4;77,78,86,85;,
  4;78,79,87,86;,
  4;79,80,88,87;,
  4;80,81,89,88;,
  4;81,82,90,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;84,77,85,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,90,98,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,85,93,100;,
  4;93,94,102,101;,
  4;94,95,103,102;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,98,106,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,93,101,108;,
  4;101,102,110,109;,
  4;102,103,111,110;,
  4;103,104,112,111;,
  4;104,105,113,112;,
  4;105,106,114,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;108,101,109,116;,
  3;62,61,117;,
  3;63,62,117;,
  3;64,63,117;,
  3;65,64,117;,
  3;66,65,117;,
  3;67,66,117;,
  3;68,67,117;,
  3;61,68,117;,
  3;109,110,118;,
  3;110,111,118;,
  3;111,112,118;,
  3;112,113,118;,
  3;113,114,118;,
  3;114,115,118;,
  3;115,116,118;,
  3;116,109,118;;
 }
 MeshTextureCoords {
  138;
  0.936194;0.674942;,
  0.948705;0.680125;,
  0.952370;0.676460;,
  0.936194;0.669760;,
  0.923683;0.680125;,
  0.920019;0.676460;,
  0.918501;0.692636;,
  0.913319;0.692636;,
  0.923683;0.705147;,
  0.920019;0.708811;,
  0.936194;0.710329;,
  0.936194;0.715511;,
  0.948705;0.705147;,
  0.952370;0.708811;,
  0.953888;0.692636;,
  0.959070;0.692636;,
  0.961216;0.667614;,
  0.936194;0.657249;,
  0.911172;0.667614;,
  0.900808;0.692636;,
  0.911172;0.717658;,
  0.936194;0.728022;,
  0.961216;0.717658;,
  0.971581;0.692636;,
  0.970063;0.658767;,
  0.936194;0.644738;,
  0.902326;0.658767;,
  0.888297;0.692636;,
  0.902326;0.726504;,
  0.936194;0.740533;,
  0.970063;0.726504;,
  0.984092;0.692636;,
  0.973727;0.655103;,
  0.936194;0.639556;,
  0.898661;0.655103;,
  0.883114;0.692636;,
  0.898661;0.730169;,
  0.936194;0.745716;,
  0.973727;0.730169;,
  0.989274;0.692636;,
  0.970063;0.658767;,
  0.936194;0.644738;,
  0.902326;0.658767;,
  0.888297;0.692636;,
  0.902326;0.726504;,
  0.936194;0.740533;,
  0.970063;0.726504;,
  0.984092;0.692636;,
  0.961216;0.667614;,
  0.936194;0.657249;,
  0.911172;0.667614;,
  0.900808;0.692636;,
  0.911172;0.717658;,
  0.936194;0.728022;,
  0.961216;0.717658;,
  0.971581;0.692636;,
  0.952370;0.676460;,
  0.936194;0.669760;,
  0.920019;0.676460;,
  0.913319;0.692636;,
  0.920019;0.708811;,
  0.936194;0.715511;,
  0.952370;0.708811;,
  0.959070;0.692636;,
  0.934698;0.605293;,
  0.913764;0.605293;,
  0.913764;0.580774;,
  0.952444;0.580774;,
  0.892831;0.605293;,
  0.875084;0.580774;,
  0.884160;0.605293;,
  0.859062;0.580774;,
  0.715130;0.614299;,
  0.723810;0.614299;,
  0.706046;0.589130;,
  0.690007;0.589130;,
  0.744765;0.614299;,
  0.744765;0.589130;,
  0.765719;0.614299;,
  0.783484;0.589130;,
  0.774399;0.614299;,
  0.799522;0.589130;,
  0.943369;0.605293;,
  0.968466;0.580774;,
  0.913764;0.544079;,
  0.964302;0.544079;,
  0.863226;0.544079;,
  0.842293;0.544079;,
  0.694176;0.551462;,
  0.673221;0.551462;,
  0.744765;0.551462;,
  0.795354;0.551462;,
  0.816308;0.551462;,
  0.985236;0.544079;,
  0.913764;0.500794;,
  0.968466;0.500794;,
  0.859062;0.500794;,
  0.836404;0.500794;,
  0.690007;0.507030;,
  0.667326;0.507030;,
  0.744765;0.507030;,
  0.799522;0.507030;,
  0.822203;0.507030;,
  0.991124;0.500794;,
  0.913764;0.457509;,
  0.964302;0.457509;,
  0.863226;0.457509;,
  0.842293;0.457509;,
  0.694176;0.462598;,
  0.673221;0.462598;,
  0.744765;0.462598;,
  0.795354;0.462598;,
  0.816308;0.462598;,
  0.985236;0.457509;,
  0.913764;0.420813;,
  0.952444;0.420813;,
  0.875084;0.420813;,
  0.859062;0.420813;,
  0.706046;0.424930;,
  0.690007;0.424930;,
  0.744765;0.424930;,
  0.783484;0.424930;,
  0.799522;0.424930;,
  0.968466;0.420813;,
  0.913764;0.396294;,
  0.934698;0.396294;,
  0.892831;0.396294;,
  0.884160;0.396294;,
  0.723810;0.399761;,
  0.715130;0.399761;,
  0.744765;0.399761;,
  0.765719;0.399761;,
  0.774399;0.399761;,
  0.943369;0.396294;,
  0.913764;0.613903;,
  0.744765;0.623137;,
  0.913764;0.387684;,
  0.744765;0.390923;;
 }
}