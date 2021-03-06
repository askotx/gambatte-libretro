/***************************************************************************
 *   Copyright (C) 2009 by Sindre Aamås                                    *
 *   aamas@stud.ntnu.no                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef FRAME_RATE_CONTROL_H
#define FRAME_RATE_CONTROL_H

#include "rational.h"

class MediaWorker;
class BlitterWidget;

class FrameRateControl {
	MediaWorker &worker_;
	BlitterWidget *blitter_;
	Rational frameTime_;
	int refreshRate_;
	bool refreshRateSync_;

	void update();

public:
	FrameRateControl(MediaWorker &worker, BlitterWidget *blitter);
	void setBlitter(BlitterWidget *blitter);
	void setFrameTime(Rational frameTime);
	void setRefreshRate(int refreshRate);
	void setRefreshRateSync(bool enable) { refreshRateSync_ = enable; update(); }
	
};

#endif
