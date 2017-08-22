#
# Be sure to run `s.dependency lib lint WorkbenchMainTest.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "ruby"
  s.version          = "2.14"
  s.summary          = "This is workbench main project. "
  s.homepage         = "http://gitlab.alibaba-inc.com/aliseller/WorkbenchMain"
  s.author           = { "xiaoluo.yxl" => "xiaoluo.yxl@alibaba-inc.com" }
  s.source           = { :git => "git@gitlab.alibaba-inc.com:aliseller/WorkbenchMain.git", :tag => s.version}
  s.platform     = :ios, '8.0'
  s.requires_arc = true
  
  s.subspec 'AppDelegate' do |ss| 
      ss.source_files = 'RubyTest/AppDelegate.*';
      ss.public_header_files = 'RubyTest/AppDelegate.h';
  end

  s.subspec 'ViewController' do |ss| 
    ss.source_files = 'RubyTest/ViewController.*';
    ss.public_header_files = 'RubyTest/ViewController.h';
    ss.dependency 'ruby/AppDelegate'
end

end
  
