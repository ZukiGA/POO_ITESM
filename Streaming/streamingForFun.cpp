
/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 06/04/20
// File: streamingForFun.cpp
*/

#include <bits/stdc++.h>
#include "StreamingMedia.hpp"

using namespace std;

//MAIN
int main() {
	//INSTANCE
	StreamingMedia myStreamingMedia;
	//TURNING ON
	myStreamingMedia.on();
	//TURNING OFF
	myStreamingMedia.off();
	//CALLING TO DESTRUCTOR
	myStreamingMedia.~StreamingMedia();
	
	return 0;
}
