#!/usr/bin/env ruby
# A regular expression that is 10 digit phone number
puts ARGV[0].scan(/^[0-9]{10}$/).join
