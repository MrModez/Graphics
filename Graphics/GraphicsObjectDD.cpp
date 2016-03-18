// ====== Copyright © 2015, MrModez (Zagir Fabarisov), All rights reserved. ====
//
// Purpose: 2D Object
//
// =============================================================================

#include "GraphicsObjectDD.h"
#include "GraphicsCameraTD.h"
#include "GraphicsCameraDD.h"
#include "GraphicsObjectTD.h"
#include "GraphicsPointDD.h"

ObjectDD::ObjectDD(std::vector<PointDD*>Object)
{
	pPointsDD = Object;
}

ObjectDD::ObjectDD()
{
}

ObjectDD::ObjectDD(String ID)
{
	ObjectID = ID;
}

ObjectDD::~ObjectDD()
{
	for (unsigned int i = 0; i < pPointsDD.size(); i++)
	{
		delete pPointsDD[i];
	}
	pPointsDD.clear();
}

float qwe;
void ObjectDD::PaintTD(DefCanvas* pCanvas, CameraTD* pCamera)
{
	qwe = 0;
	for (unsigned int j = 0; j < pPointsDD.size(); j++)
	{
		qwe = pPointsDD[j]->fX * 0.55 + 220;
		PointDD* pObjectDD = pPointsDD[j];
		SetCanvasSettings(pCanvas);
		switch (pObjectDD->iAction)
		{
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_DRAW:
			if (j > 1 && pPointsDD[j - 2] == pObjectDD)
				pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			else
				pCanvas->LineTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_NONE:
			switch (pPointsDD[j]->iType)
			{
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY,
					pPointsDD[j]->sText);
				pCanvas->Font->Size = 8 + pCamera->iZShift / 10.0;
				break;
			case TYPE_POINT:
				pCanvas->Ellipse(pObjectDD->fX - DEFAULT_RADIUS,
					pObjectDD->fY - DEFAULT_RADIUS,
					pObjectDD->fX + DEFAULT_RADIUS,
					pObjectDD->fY + DEFAULT_RADIUS);
				break;
			default:
				// pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY, this->ObjectID);
				break;
			}
			break;
		default:
			break;
		}
		SetCanvasDefaults(pCanvas);
	}
}

void ObjectDD::PaintDD(DefCanvas* pCanvas, CameraDD* pCamera)
{
	for (unsigned int j = 0; j < pPointsDD.size(); j++)
	{
		qwe = pPointsDD[j]->fX * 0.55 + 220;
		PointDD* pObjectDDL = pPointsDD[j - 1];
		PointDD* pObjectDD = pPointsDD[j];
		SetCanvasSettings(pCanvas);
		switch (pObjectDD->iAction)
		{
		case ACT_MOVE:
			pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_DRAW:
			pCanvas->LineTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_ARC:
			pCanvas->Arc(2 * pObjectDD->fX - pObjectDDL->fX,
				2 * pObjectDDL->fY - pObjectDD->fY, pObjectDDL->fX,
				pObjectDD->fY, pObjectDD->fX, pObjectDD->fY, pObjectDDL->fX,
				pObjectDDL->fY);
			pCanvas->MoveTo(pObjectDD->fX, pObjectDD->fY);
			break;
		case ACT_NONE:
			switch (pPointsDD[j]->iType)
			{
			case TYPE_TEXT:
				pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY,
					pPointsDD[j]->sText);
				pCanvas->Font->Size = 8 + pCamera->iZShift / 10.0;
				break;
			case TYPE_POINT:
				pCanvas->Ellipse(pObjectDD->fX - DEFAULT_RADIUS,
					pObjectDD->fY - DEFAULT_RADIUS,
					pObjectDD->fX + DEFAULT_RADIUS,
					pObjectDD->fY + DEFAULT_RADIUS);
				break;
			default:
				// pCanvas->TextOutW(pObjectDD->fX, pObjectDD->fY, this->ObjectID);
				break;
			}
			break;
		default:
			break;
		}
		SetCanvasDefaults(pCanvas);
	}
}

void ObjectDD::SetParameters(DrawPar P)
{
	Par = P;
};

void ObjectDD::AddPoint(PointDD * Point)
{
	pPointsDD.push_back(Point);
}


void ObjectDD::SetCanvasSettings(DefCanvas* pCanvas)
{
	pCanvas->Pen->Width = Par.iWidth;
	pCanvas->Pen->Color = Par.iColor + qwe;
	pCanvas->Pen->Style = Par.iStyle;
	pCanvas->Brush->Style = bsClear;
}

void ObjectDD::SetCanvasDefaults(DefCanvas* pCanvas)
{
	pCanvas->Pen->Width = DEFAULT_WIDTH;
	pCanvas->Pen->Color = DEFAULT_COLOR;
	pCanvas->Pen->Style = DEFAULT_STYLE;
}
