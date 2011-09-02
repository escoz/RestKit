//
//  NSString+RestKit.h
//  RestKit
//
//  Created by Blake Watters on 6/15/11.
//  Copyright 2011 Two Toasters. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A library of helpful additions to the NSString class to simplify
 common tasks within RestKit
 */
@interface NSString (RestKit)

/**
 Returns a resource path from a dictionary of query parameters URL encoded and appended
 This is a convenience method for constructing a new resource path that includes a query. For example,
 when given a resourcePath of /contacts and a dictionary of parameters containing foo=bar and color=red,
 will return /contacts?foo=bar&amp;color=red
 
 *NOTE* - Assumes that the resource path does not already contain any query parameters.
 @param queryParams A dictionary of query parameters to be URL encoded and appended to the resource path
 @return A new resource path with the query parameters appended
 @see RKPathAppendQueryParams
 */
- (NSString*)appendQueryParams:(NSDictionary*)queryParams;

/**
 Convenience method for generating a path against the properties of an object. Takes
 a string with property names encoded in parentheses and interpolates the values of
 the properties specified and returns the generated path.
 
 For example, given an 'article' object with an 'articleID' property of 12345
 [@"articles/(articleID)" interpolateWithObject:article] would generate @"articles/12345"
 This functionality is the basis for resource path generation in the Router.
 
 @param object The object to interpolate the properties against
 */
- (NSString*)interpolateWithObject:(id)object;

/**
 Returns a dictionary of parameter keys and values given a URL-style query string
 on the receiving object. For example, when given the string /contacts?foo=bar&amp;color=red, 
 this will return a dictionary of parameters containing foo=bar and color=red, excludes the path "/contacts?"
 
 This method originally appeared as queryContentsUsingEncoding: in the Three20 project:
 https://github.com/facebook/three20/blob/master/src/Three20Core/Sources/NSStringAdditions.m
 
 @param receiver A string in the form of @"/object/?sortBy=name", or @"/object/?sortBy=name&color=red"
 @param encoding The encoding for to use while parsing the query string.
 @return A new dictionary of query parameters, with keys like 'sortBy' and values like 'name'.
 */
- (NSDictionary*)queryParametersUsingEncoding:(NSStringEncoding)encoding;

@end
