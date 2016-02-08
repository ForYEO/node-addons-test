'use strict';

var addon = require('../addon/build/Release/hello');

addon.hello('hello, world', function (msg) {
	console.log(msg);
});
