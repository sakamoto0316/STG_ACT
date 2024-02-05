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
 198;
 -11.92905;8.89870;-15.14619;,
 20.21795;8.89870;-15.14619;,
 20.21795;-19.49162;-15.14619;,
 -11.92905;-19.49162;-15.14619;,
 20.21795;8.89870;-15.14619;,
 20.21795;8.89870;13.80168;,
 20.21795;-19.49162;13.80168;,
 20.21795;-19.49162;-15.14619;,
 20.21795;8.89870;13.80168;,
 -11.92905;8.89870;13.80168;,
 -11.92905;-19.49162;13.80168;,
 20.21795;-19.49162;13.80168;,
 -11.92905;8.89870;13.80168;,
 -11.92905;8.89870;-15.14619;,
 -11.92905;-19.49162;-15.14619;,
 -11.92905;-19.49162;13.80168;,
 20.21795;8.89870;-15.14619;,
 -11.92905;8.89870;-15.14619;,
 -11.92905;-19.49162;-15.14619;,
 20.21795;-19.49162;-15.14619;,
 1.63655;13.98808;-7.73013;,
 17.31224;13.98808;-7.73013;,
 17.31224;5.99000;-7.73013;,
 1.63655;5.99000;-7.73013;,
 17.31224;13.98808;-7.73013;,
 17.31224;13.98808;6.38559;,
 17.31224;5.99000;6.38559;,
 17.31224;5.99000;-7.73013;,
 17.31224;13.98808;6.38559;,
 1.63655;13.98808;6.38559;,
 1.63655;5.99000;6.38559;,
 17.31224;5.99000;6.38559;,
 1.63655;13.98808;6.38559;,
 1.63655;13.98808;-7.73013;,
 1.63655;5.99000;-7.73013;,
 1.63655;5.99000;6.38559;,
 17.31224;13.98808;-7.73013;,
 1.63655;13.98808;-7.73013;,
 1.63655;5.99000;-7.73013;,
 17.31224;5.99000;-7.73013;,
 8.77619;17.14263;-4.70940;,
 18.43932;17.14263;-4.70940;,
 18.43932;10.55830;-4.70940;,
 8.77619;10.55830;-4.70940;,
 18.43932;17.14263;-4.70940;,
 18.43932;17.14263;3.36487;,
 18.43932;10.55830;3.36487;,
 18.43932;10.55830;-4.70940;,
 18.43932;17.14263;3.36487;,
 8.77619;17.14263;3.36487;,
 8.77619;10.55830;3.36487;,
 18.43932;10.55830;3.36487;,
 8.77619;17.14263;3.36487;,
 8.77619;17.14263;-4.70940;,
 8.77619;10.55830;-4.70940;,
 8.77619;10.55830;3.36487;,
 18.43932;17.14263;-4.70940;,
 8.77619;17.14263;-4.70940;,
 8.77619;10.55830;-4.70940;,
 18.43932;10.55830;-4.70940;,
 15.79309;19.40470;-2.80441;,
 19.69155;19.40470;-2.80441;,
 19.69155;15.92730;-2.80441;,
 15.79309;15.92730;-2.80441;,
 19.69155;19.40470;-2.80441;,
 19.69155;19.40470;1.45988;,
 19.69155;15.92730;1.45988;,
 19.69155;15.92730;-2.80441;,
 19.69155;19.40470;1.45988;,
 15.79309;19.40470;1.45988;,
 15.79309;15.92730;1.45988;,
 19.69155;15.92730;1.45988;,
 15.79309;19.40470;1.45988;,
 15.79309;19.40470;-2.80441;,
 15.79309;15.92730;-2.80441;,
 15.79309;15.92730;1.45988;,
 19.69155;19.40470;-2.80441;,
 15.79309;19.40470;-2.80441;,
 15.79309;15.92730;-2.80441;,
 19.69155;15.92730;-2.80441;,
 -19.78205;-9.14159;-20.84044;,
 -0.45342;-9.14159;-20.84044;,
 -0.45342;-20.59530;-20.84044;,
 -19.78205;-20.59530;-20.84044;,
 -0.45342;-9.14159;-20.84044;,
 -0.45342;-9.14159;-12.22527;,
 -0.45342;-20.59530;-12.22527;,
 -0.45342;-20.59530;-20.84044;,
 -0.45342;-9.14159;-12.22527;,
 -19.78205;-9.14159;-12.22527;,
 -19.78205;-20.59530;-12.22527;,
 -0.45342;-20.59530;-12.22527;,
 -19.78205;-9.14159;-12.22527;,
 -19.78205;-9.14159;-20.84044;,
 -19.78205;-20.59530;-20.84044;,
 -19.78205;-20.59530;-12.22527;,
 -0.45342;-9.14159;-20.84044;,
 -19.78205;-9.14159;-20.84044;,
 -19.78205;-20.59530;-20.84044;,
 -0.45342;-20.59530;-20.84044;,
 -19.78205;-9.14159;10.54439;,
 -0.45342;-9.14159;10.54439;,
 -0.45342;-20.59530;10.54439;,
 -19.78205;-20.59530;10.54439;,
 -0.45342;-9.14159;10.54439;,
 -0.45342;-9.14159;19.15956;,
 -0.45342;-20.59530;19.15956;,
 -0.45342;-20.59530;10.54439;,
 -0.45342;-9.14159;19.15956;,
 -19.78205;-9.14159;19.15956;,
 -19.78205;-20.59530;19.15956;,
 -0.45342;-20.59530;19.15956;,
 -19.78205;-9.14159;19.15956;,
 -19.78205;-9.14159;10.54439;,
 -19.78205;-20.59530;10.54439;,
 -19.78205;-20.59530;19.15956;,
 -0.45342;-9.14159;10.54439;,
 -19.78205;-9.14159;10.54439;,
 -19.78205;-20.59530;10.54439;,
 -0.45342;-20.59530;10.54439;,
 -12.58577;2.46018;1.73939;,
 -9.40830;2.46018;1.73939;,
 -9.40830;-5.03587;1.73939;,
 -12.58577;-5.03587;1.73939;,
 -9.40830;2.46018;1.73939;,
 -9.40830;2.46018;8.28772;,
 -9.40830;-5.03587;8.28772;,
 -9.40830;-5.03587;1.73939;,
 -9.40830;2.46018;8.28772;,
 -12.58577;2.46018;8.28772;,
 -12.58577;-5.03587;8.28772;,
 -9.40830;-5.03587;8.28772;,
 -12.58577;2.46018;8.28772;,
 -12.58577;2.46018;1.73939;,
 -12.58577;-5.03587;1.73939;,
 -12.58577;-5.03587;8.28772;,
 -9.40830;2.46018;1.73939;,
 -12.58577;2.46018;1.73939;,
 -12.58577;-5.03587;1.73939;,
 -9.40830;-5.03587;1.73939;,
 -12.83791;2.46018;-9.76654;,
 -9.66042;2.46018;-9.76654;,
 -9.66042;-5.03587;-9.76654;,
 -12.58577;-5.03587;-9.76654;,
 -9.66042;2.46018;-3.21822;,
 -12.58577;2.46018;-3.21822;,
 -12.58577;-5.03587;-3.21822;,
 -9.66042;-5.03587;-3.21822;,
 -12.58577;2.46018;-3.21822;,
 -12.83791;2.46018;-9.76654;,
 -12.58577;-5.03587;-9.76654;,
 -12.58577;-5.03587;-3.21822;,
 -9.66042;2.46018;-3.21822;,
 -9.66042;2.46018;-9.76654;,
 -12.83791;2.46018;-9.76654;,
 -12.58577;-5.03587;-9.76654;,
 -9.66042;-5.03587;-9.76654;,
 -9.66042;-5.03587;-3.21822;,
 -12.88460;1.21629;-8.16245;,
 -9.70710;1.21629;-8.16245;,
 -9.70710;-2.33121;-8.16245;,
 -12.88460;-2.33121;-8.16245;,
 -9.70710;1.21629;-8.16245;,
 -9.70710;1.21629;-4.73838;,
 -9.70710;-2.33121;-4.73838;,
 -9.70710;-2.33121;-8.16245;,
 -9.70710;1.21629;-4.73838;,
 -12.88460;1.21629;-4.73838;,
 -12.88460;-2.33121;-4.73838;,
 -9.70710;-2.33121;-4.73838;,
 -12.88460;1.21629;-4.73838;,
 -12.88460;1.21629;-8.16245;,
 -12.88460;-2.33121;-8.16245;,
 -12.88460;-2.33121;-4.73838;,
 -9.70710;1.21629;-8.16245;,
 -12.88460;1.21629;-8.16245;,
 -12.88460;-2.33121;-8.16245;,
 -9.70710;-2.33121;-8.16245;,
 -12.88460;1.21629;3.40162;,
 -9.70710;1.21629;3.40162;,
 -9.70710;-2.33121;3.40162;,
 -12.88460;-2.33121;3.40162;,
 -9.70710;1.21629;3.40162;,
 -9.70710;1.21629;6.82569;,
 -9.70710;-2.33121;6.82569;,
 -9.70710;-2.33121;3.40162;,
 -9.70710;1.21629;6.82569;,
 -12.88460;1.21629;6.82569;,
 -12.88460;-2.33121;6.82569;,
 -9.70710;-2.33121;6.82569;,
 -12.88460;1.21629;6.82569;,
 -12.88460;1.21629;3.40162;,
 -12.88460;-2.33121;3.40162;,
 -12.88460;-2.33121;6.82569;,
 -9.70710;1.21629;3.40162;,
 -12.88460;1.21629;3.40162;,
 -12.88460;-2.33121;3.40162;,
 -9.70710;-2.33121;3.40162;;
 
 59;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,25,36,37;,
 4;38,39,26,35;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,45,56,57;,
 4;58,59,46,55;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;72,65,76,77;,
 4;78,79,66,75;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;92,85,96,97;,
 4;98,99,86,95;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;112,105,116,117;,
 4;118,119,106,115;,
 4;120,121,122,123;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;132,125,136,137;,
 4;138,139,126,135;,
 4;140,141,142,143;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;148,152,153,154;,
 4;155,156,157,151;,
 4;158,159,160,161;,
 4;162,163,164,165;,
 4;166,167,168,169;,
 4;170,171,172,173;,
 4;170,163,174,175;,
 4;176,177,164,173;,
 4;178,179,180,181;,
 4;182,183,184,185;,
 4;186,187,188,189;,
 4;190,191,192,193;,
 4;190,183,194,195;,
 4;196,197,184,193;;
 
 MeshMaterialList {
  3;
  59;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1;;
  Material {
   0.627451;0.238431;0.031373;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  7;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.999674;-0.016802;0.019233;;
  59;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;6,6,6,6;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  198;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}