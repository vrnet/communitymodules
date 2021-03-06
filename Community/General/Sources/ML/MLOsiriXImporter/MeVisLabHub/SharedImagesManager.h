//
//  SharedImagesManager.h
//  MLOsiriXImporter_debug
//
//  Created by chuwa on 8/4/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SharedImagesManager : NSObject {
	NSMutableArray* allocatedImages;
	long uniqueIndex;
	NSString* uniqueMemoryIDStringPrefix;
}
- (id)initWithIDStringPrefix:(NSString*)astring ;
- (void)releaseAllImages;
- (void)removeImage:(NSMutableDictionary*)anImage;
- (BOOL)creatASharedImage:(NSMutableDictionary*)newImage ForDescription:(NSString*)description SupportSharedMem:(BOOL)ifSupportMemorySharing;
- (void*)getMemoryPtrForImageDescription:(NSString*)description;
- (NSDictionary*)getImageForDescription:(NSString*)description;
- (BOOL)allocMemoryBlock:(NSMutableDictionary*)anImage;
- (BOOL)allocSharedMemoryBlock:(NSMutableDictionary*)anImage;
@end
