
$hash_value = Hash.new;

def source(url)
    $hash_value['source'] = url
end

def target(target)
    targets = $hash_value['targets']
    targets = [] if targets == nil
    targets << target
    $hash_value['targets'] = targets
    yield if block_given?
end

def platform(platform, version)
end

def pod(pod, version)
    pods = $hash_value['pods']
    pods = [] if pods == nil
    pods << pod
    $hash_value['pods'] = pods
end

# 加载Podfile
content = File.read './Podfile'
eval content
p $hash_value


