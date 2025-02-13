/*
 *  MapboxMultiSourcetileInfo.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 2/23/15.
 *  Copyright 2011-2022 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "MaplyTileSource.h"
#import "MapboxVectorTiles.h"

/// The various types of style that will work with Mapnik vector tiles
typedef NS_ENUM(NSInteger, MapnikStyleType) {
    MapnikXMLStyle,
    MapnikSLDStyle
};

/** 
    Used to represent a Mapbox source compiled from multiple individual sources.
    
    You can use these to merge different sources together (assuming they can be merged), returning image and/or vector tiles.
  */
@interface MapboxMultiSourceTileInfo : MaplyRemoteTileInfo <MaplyRemoteTileSourceDelegate>

/** 
    Initialze the multi source tile info object.  Fill in everything else later.
  */
- (nonnull instancetype)initWithViewC:(NSObject<MaplyRenderControllerProtocol> *__nonnull)viewC;

/** 
    The object needs this if you're parsing vector tiles.
  */
@property (nonatomic,weak, nullable) MaplyQuadImageTilesLayer *imageLayer;

/** 
    The cache directory where we'll store combo tiles.
    
    If set, we'll store the cached returns for image and/or vector tiles.  If not set, we won't cache.
  */
//@property (nonatomic,strong) NSString *cacheDir;

/** 
    If set, we'll use an access key to get map data.
  */
@property (nonatomic,strong, nullable) NSString *accessToken;

/** 
    Add an image based map covering the given levels.
    
    This adds an image based map of the given type (e.g. jpg or png) at the given levels.
  */
- (bool)addImageMap:(NSString *__nonnull)map minZoom:(int)minZoom maxZoom:(int)maxZoom type:(NSString *__nonnull)imageType;

/** 
    Add a vector map at the given levels.
    
    This adds a vector map for the given levels
  */
- (bool)addVectorMap:(NSString *__nonnull)map style:(NSData *__nonnull)styleSheet styleType:(MapnikStyleType)styleType minZoom:(int)minZoom maxZoom:(int)maxZoom;

/** 
    Add a vector or image map, depending on the tile spec.
    
    This version parses a tile spec and figures out what we're loading from there.
  */
- (bool)addTileSpec:(NSDictionary *__nonnull)tileSpec;

/** 
    Add a vector or image map, depending on the tile spec.
    
    This version parses a tile spec and figures out what we're loading from there.
    
    You can also override which zoom levels to use.
 */
- (bool)addTileSpec:(NSDictionary *__nonnull)tileSpec minZoom:(int)minZoom maxZoom:(int)maxZoom;

@end
