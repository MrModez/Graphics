#ifndef GraphicsModule
#define GraphicsModule

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Direct2D.hpp>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <Graphics.hpp>

/*
 class OCamera;

 class ObjectTD;
 class PointTD;
 class PointDD;

 class OrtoSystem {
 public:
 OrtoSystem() {
 PI = 3.14159265;
 };

 OrtoSystem(OCamera* Camera) {
 pCamera = Camera;
 PI = 3.14159265;
 };

 void Paint(TDirect2DCanvas* pCanvas);

 void AddObject(ObjectTD * pObject) {
 pObjects.push_back(pObject);
 };

/* TPointF GetVector(int X, int Y, int D) {
 float uX = X;
 float uY = Y - 1;
 float tX = (uX - X) * cos(D * PI / 180.0) - (uY - Y) * sin
 (D * PI / 180.0);
 float tY = (uY - Y) * cos(D * PI / 180.0) + (uX - X) * sin
 (D * PI / 180.0);
 return PointF(tX, tY);
 }; */
/*
 int iScale;
 OCamera* pCamera;

 std::vector<ObjectTD*>pObjects;

 float PI;
 };

 class OCamera {
 public:
 OCamera(int xshift, int yshift, int zshift, float pitch, float roll,
 float yaw) {
 fPitch = pitch;
 fRoll = roll;
 fYaw = yaw;
 iXShift = xshift;
 iYShift = yshift;
 iZShift = zshift;
 }

 void SetRotation(float pitch, float roll, float yaw) {
 fPitch = pitch;
 fRoll = roll;
 fYaw = yaw;
 }

 // private:
 float fPitch, fRoll, fYaw;
 int iXShift, iYShift, iZShift;
 };

 enum Action {
 move, draw
 };

 enum Axis {
 AxisX, AxisY, AxisZ
 };

 class ObjectTD {
 public:
 ObjectTD(std::vector<PointTD*>Object) {
 pObject = Object;
 }

 ObjectTD() {
 }

 void AddPoint(PointTD * Point) {
 pObject.push_back(Point);
 }

 // ObjectTD;
 std::vector<PointTD*>pObject;
 };

 class ObjectDD {
 public:
 ObjectDD(std::vector<PointDD*>Object) {
 pObject = Object;
 }

 ObjectDD() {
 }

 void AddPoint(PointDD * Point) {
 pObject.push_back(Point);
 }

 // ObjectTD;
 std::vector<PointDD*>pObject;
 };

 class PointTD {
 public:
 PointTD(float ix, float iy, float iz, int iA) {
 x = ix;
 y = iy;
 z = iz;
 action = iA;
 };

 PointTD & operator = (const PointTD & rhs) {
 x = rhs.x;
 y = rhs.y;
 z = rhs.z;
 action = rhs.action;

 };

 float x;
 float y;
 float z;
 Action action;
 };

 class PointDD {
 public:
 PointDD(float ix, float iy, int iA) {
 x = ix;
 y = iy;
 action = iA;
 };

 PointDD(PointTD & rhs) {
 x = rhs.x;
 y = rhs.y;
 action = rhs.action;
 };

 PointDD & operator = (const PointTD & rhs) {
 x = rhs.x;
 y = rhs.y;
 action = rhs.action;
 };

 PointDD & operator = (const PointDD & rhs) {
 x = rhs.x;
 y = rhs.y;
 action = rhs.action;
 };

 float x;
 float y;
 float z;
 Action action;
 };

 class ProjectionDD {
 public:
 ProjectionDD(ObjectTD* pObjectTD, OCamera* pCamera) {
 pProjection = Projection(pObjectTD, pCamera);
 }

 ObjectTD* Projection(ObjectTD* pObjectTD, OCamera* pCamera) {
 PointTD* origin = new PointTD(0, 0, 0, move);
 ObjectDD* Points;
 for (int i = 0; i < pObjectTD->; i++) {
 ///
 // DEBUG("before: " + STR(object[i].x) + " " + STR(object[i].y) + " " +
 // STR(object[i].z));

 pObjectTD[i] = Rotate3D(object[i], origin, AxisX, DegToRad(Pitch));
 pObjectTD[i] = Rotate3D(object[i], origin, AxisY, DegToRad(Roll));
 pObjectTD[i] = Rotate3D(object[i], origin, AxisZ, DegToRad(Yaw));

 // DEBUG("after: " + STR(object[i].x) + " " + STR(object[i].y) + " " +
 // STR(object[i].z));

 // calculating screen coordinates
 object[i].x = dist_to_screen * object[i].x + xshift;
 object[i].y = dist_to_screen * object[i].y + yshift;

 Points.push_back(object[i]);
 }
 return Points;
 };

 // ObjectTD;
 ObjectTD *pProjection;
 }; */

#endif
