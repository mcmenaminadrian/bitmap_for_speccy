/* $Xorg: Requests.h,v 1.4 2001/02/09 02:05:28 xorgcvs Exp $ */
/*

Copyright 1989, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.

*/

/*
 * Author:  Davor Matic, MIT X Consortium
 */

typedef struct {
    Boolean  success;
    Position at_x, at_y;
    Position from_x, from_y,
             to_x, to_y;
    void   (*draw)();
    int      value;
    Time     btime;
    int      state;
} BWStatus;

void OnePointEngage();
void OnePointTerminate();
void OnePointTerminateTransparent();
void DragOnePointEngage();
void DragOnePointTerminate();
void TwoPointsEngage();
void TwoPointsTerminate();
void TwoPointsTerminateTransparent();
void TwoPointsTerminateTimed();
void DragTwoPointsEngage();
void DragTwoPointsTerminate();
void Interface();
void Paste();

void BWMark();
void BWUnmark();
void BWStore();
void BWDragMarked();
void BWDragStored();
void BWRestore();
void BWCopy();
void BWMove();
void BWDrawPoint();
void BWDrawLine();
void BWBlindLine();
void BWDrawRectangle();
void BWDrawFilledRectangle();
void BWDrawCircle();
void BWDrawFilledCircle();
void BWFloodFill();
void BWDrawHotSpot();
void BWChangeNotify();
void BWZoomIn();

static BWRequestRec requests[] = /* SUPPRESS 592 */
{
{MarkRequest, sizeof(BWStatus),
     TwoPointsEngage, (XtPointer) BWDrawRectangle,
     TwoPointsTerminateTimed, (XtPointer) BWSelect,
     NULL, (XtPointer) NULL},
{RestoreRequest, sizeof(BWStatus),
     OnePointEngage, (XtPointer) BWDragStored,
     OnePointTerminate, (XtPointer) BWRestore,
     NULL, (XtPointer) NULL},
{ImmediateCopyRequest, sizeof(BWStatus),
     OnePointEngage, (XtPointer) BWDragMarked,
     OnePointTerminate, (XtPointer) BWCopy,
     NULL, (XtPointer) NULL},
{ImmediateMoveRequest, sizeof(BWStatus),
     OnePointEngage, (XtPointer) BWDragMarked,
     OnePointTerminate, (XtPointer) BWMove,
     NULL, (XtPointer) NULL},
{CopyRequest, sizeof(BWStatus),
     DragOnePointEngage, (XtPointer) Paste,
     DragOnePointTerminate, (XtPointer) ImmediateCopyRequest,
     Interface, (XtPointer) BWUnmark},
{MoveRequest, sizeof(BWStatus),
     DragOnePointEngage, (XtPointer) Paste,
     DragOnePointTerminate, (XtPointer) ImmediateMoveRequest,
     Interface, (XtPointer) BWUnmark},
{PointRequest, sizeof(BWStatus),
     DragOnePointEngage, (XtPointer) BWDrawPoint,
     DragOnePointTerminate, (XtPointer) BWDrawPoint,
     NULL, (XtPointer) NULL},
{CurveRequest, sizeof(BWStatus),
     DragTwoPointsEngage, (XtPointer) BWBlindLine,
     DragTwoPointsTerminate, (XtPointer) BWBlindLine,
     NULL, (XtPointer) NULL},
{LineRequest, sizeof(BWStatus), 
     TwoPointsEngage, (XtPointer) BWDrawLine, 
     TwoPointsTerminate, (XtPointer) BWDrawLine,
     NULL, (XtPointer) NULL},
{RectangleRequest, sizeof(BWStatus), 
     TwoPointsEngage, (XtPointer) BWDrawRectangle,
     TwoPointsTerminate, (XtPointer) BWDrawRectangle,
     NULL, (XtPointer) NULL},
{FilledRectangleRequest, sizeof(BWStatus), 
     TwoPointsEngage, (XtPointer) BWDrawRectangle,
     TwoPointsTerminate, (XtPointer) BWDrawFilledRectangle,
     NULL, (XtPointer) NULL},
{CircleRequest, sizeof(BWStatus), 
     TwoPointsEngage, (XtPointer) BWDrawCircle,
     TwoPointsTerminate, (XtPointer) BWDrawCircle,
     NULL, (XtPointer) NULL},
{FilledCircleRequest, sizeof(BWStatus), 
     TwoPointsEngage, (XtPointer) BWDrawCircle, 
     TwoPointsTerminate, (XtPointer) BWDrawFilledCircle,
     NULL, (XtPointer) NULL},
{FloodFillRequest, sizeof(BWStatus),
     OnePointEngage, (XtPointer) NULL,
     OnePointTerminate, (XtPointer) BWFloodFill,
     NULL, (XtPointer) NULL},
{HotSpotRequest, sizeof(BWStatus),
     OnePointEngage, (XtPointer) BWDrawHotSpot,
     OnePointTerminate, (XtPointer) BWDrawHotSpot,
     NULL, (XtPointer) NULL},
{ZoomInRequest, sizeof(BWStatus),
     TwoPointsEngage, (XtPointer) BWDrawRectangle,
     TwoPointsTerminate, (XtPointer) BWZoomIn,
     NULL, (XtPointer) NULL},
};

